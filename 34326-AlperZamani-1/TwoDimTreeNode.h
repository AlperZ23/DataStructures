#ifndef TWODIMTREENODE_H
#define TWODIMTREENODE_H

#include "Rectangle.h"
#include "Linkedlist.h"

class TwoDimTreeNode {
public:
    Rectangle Extent;
    List<Rectangle> Vertical, Horizontal; // Rectangles intersecting vertical AND horizontal
    TwoDimTreeNode *TopLeft, *TopRight,
    *BottomLeft, *BottomRight;

    // Constructor
    TwoDimTreeNode(int top, int left, int bottom, int right);

    // Destructor
    ~TwoDimTreeNode();

    // Insert a rectangle into node
    void insertRectangle(const Rectangle& rect);
};

#endif
