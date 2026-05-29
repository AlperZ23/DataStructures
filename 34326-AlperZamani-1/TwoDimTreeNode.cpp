#include "TwoDimTreeNode.h"


//TwoDimTreeNode Constructor
TwoDimTreeNode::TwoDimTreeNode(int top, int left, int bottom, int right) : Extent(top, left, bottom, right),
      TopLeft(nullptr), TopRight(nullptr),
      BottomLeft(nullptr), BottomRight(nullptr)
{

}

//TwoDimTreeNode Destructor
TwoDimTreeNode::~TwoDimTreeNode() {

    delete TopLeft;
    delete TopRight;
    delete BottomLeft;
    delete BottomRight;
}

void TwoDimTreeNode::insertRectangle(const Rectangle& rect) {
    // If rectangle completely outside this node extent then do nothing
    if (rect.getRight() <= Extent.getLeft() || rect.getLeft() >= Extent.getRight() ||
        rect.getBottom() <= Extent.getTop() || rect.getTop() >= Extent.getBottom()) {


        return;

    }


    // Calculation center lines
    int midX = (Extent.getLeft() + Extent.getRight()) / 2;
    int midY = (Extent.getTop() + Extent.getBottom()) / 2;
    bool x_vert   = (rect.getLeft() <= midX && rect.getRight() > midX);
    bool x_horiz = (rect.getTop() <= midY && rect.getBottom() > midY);



    // 1) Rectangle intersects the vertical center line
    if (x_vert) {


        Vertical.insert(rect, Vertical.zeroth());
        return;
    }
    // 22) Rectangle intersects the horizontal center line
    if (x_horiz) {

        Horizontal.insert(rect, Horizontal.zeroth());

        return;
    }

    //  3) Rectangle does not cross either center line
    if ((Extent.getRight() - Extent.getLeft()) <= 1 || (Extent.getBottom() - Extent.getTop()) <= 1) {

        Vertical.insert(rect, Vertical.zeroth());
        return;

    }

    // Determine which quadrant the rectangle has
    if (rect.getRight() <= midX && rect.getBottom() <= midY) {
        // TopLeft 
        if (!TopLeft) {

            TopLeft = new TwoDimTreeNode(Extent.getTop(), Extent.getLeft(), midY, midX);
        }
        TopLeft->insertRectangle(rect);
    }
    else if (rect.getLeft() > midX && rect.getBottom() <= midY) {
        // TopRight quadrant
        if (!TopRight) {
            TopRight = new TwoDimTreeNode(Extent.getTop(), midX + 1, midY, Extent.getRight());
        }
        TopRight->insertRectangle(rect);
    }
    else if (rect.getRight() <= midX && rect.getTop() > midY) {
        // BottomLeft quadrant
        if (!BottomLeft) {

            BottomLeft = new TwoDimTreeNode(midY + 1, Extent.getLeft(), Extent.getBottom(), midX);

        }


        BottomLeft->insertRectangle(rect);
    }
    else if (rect.getLeft() > midX && rect.getTop() > midY) {
        // BottomRight quadrant
        if (!BottomRight) {
            BottomRight = new TwoDimTreeNode(midY + 1, midX + 1, Extent.getBottom(), Extent.getRight());


        }
        BottomRight->insertRectangle(rect);
    }
   
}
