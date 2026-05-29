#include "TwoDimTree.h"



// Recursive function for searching the quadtree
static void searchNode(TwoDimTreeNode* node, int px, int py, List<Rectangle>& res) {

    if (!node) {
        return;
    };


    // Check all rectangles in this node vertical list
    for (ListItr<Rectangle> itr = node->Vertical.first(); !itr.isPastEnd(); itr.advance()) {
        if (const Rectangle& rect = itr.retrieve(); rect.contains(px, py)) {
            res.insert(rect, res.zeroth());
        }
    }


    // Check all rectangles in the horizontal list
    for (ListItr<Rectangle> itr = node->Horizontal.first(); !itr.isPastEnd(); itr.advance()) {
        const Rectangle& rect = itr.retrieve();
        if (rect.contains(px, py)) {
            res.insert(rect, res.zeroth());
        }
    }


    // Determine center lines of current node
    int midX = (node->Extent.getLeft() + node->Extent.getRight()) / 2;
    int midY = (node->Extent.getTop() + node->Extent.getBottom()) / 2;


    // If the point lies on a center line
    if (px == midX || py == midY) {
        return;
    }


    // Recurse into the quadrant that contains the point
    if (px < midX && py < midY) {
        searchNode(node->TopLeft, px, py, res);
    }
    else if (px > midX && py < midY) {
        searchNode(node->TopRight, px, py, res);
    }
    else if (px < midX && py > midY) {
        searchNode(node->BottomLeft, px, py, res);
    }
    else if (px > midX && py > midY) {
        searchNode(node->BottomRight, px, py, res);
    }

}

void TwoDimTree::resListsum(const int x, const int y, List<Rectangle>& resultList) const {


    // Clear any previous results
    resultList.makeEmpty();
    searchNode(node, x, y, resultList);

}
