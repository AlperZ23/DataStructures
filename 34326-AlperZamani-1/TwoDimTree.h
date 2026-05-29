#ifndef TWODIMTREE_H
#define TWODIMTREE_H

#include "TwoDimTreeNode.h"
#include "Rectangle.h"
#include "Linkedlist.h"

class TwoDimTree {
private:
    TwoDimTreeNode* node;  // node of the quadtree
public:

    // Constructor
    TwoDimTree(const int top, const int left, const int bottom, const int right) {
        node = new TwoDimTreeNode(top, left, bottom, right);
    }

    // Destructor
    ~TwoDimTree() {
        delete node;
    }

    // Insert a rectangle into the quadtree
    void insert(const Rectangle& rect) const {
        if (node) node->insertRectangle(rect);
    }

    // all rectangles that contain the point and results are appended to resultList
    void resListsum(int x, int y, List<Rectangle>& resultList) const;
};

#endif
