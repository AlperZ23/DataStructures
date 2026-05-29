#include <iostream>
#include <fstream>
#include "TwoDimTree.h"
using namespace std;


int main() {

    ifstream infile("rectdb.txt");

    if (!infile) {
        cout << "Unable to open rectdb.txt file." << endl;
        return 1;
    }

    // Read the extent rectangle of the whole tree
    int top, left, bottom, right;
    infile >> top;


    if (!infile) {
       cout << "Invalid input format in rectdb.txt." << endl;
        return 1;
    }

    if (top < 0) {
        return 0;
    }

    infile >> left;
    infile >> bottom;
    infile >> right;

    TwoDimTree twodimtree(top, left, bottom, right);

    // Read and insert each rectangle from the file until a  -1
    while (true) {
        int t;
        infile >> t;

        if (!infile) break;
        if (t < 0) {  // terminator for rectangle list
            break;
        }

        int l;
        int b;
        int r;

        infile >> l;
        infile >> b;
        infile >> r;

        Rectangle rect(t, l, b, r);
        twodimtree.insert(rect);
    }
    infile.close();

    // Read  points from input
    int qx;
    int qy;
    List<Rectangle> resultList;

    while (true) {
        if (!(cin >> qx)) {
            return 0;  // no more input
        }
        if (qx < 0) {
            break;      // x = -1 termination
        }
        cin >> qy;
        twodimtree.resListsum(qx, qy, resultList);
        // Count how many rectangles contain this point
        int count = 0;
        for (ListItr<Rectangle> itr = resultList.first(); !itr.isPastEnd(); itr.advance()) {
            count++;
        }
        // Output the results
       cout << qx << " " << qy << endl;
        cout << count;
        for (ListItr<Rectangle> itr = resultList.first(); !itr.isPastEnd(); itr.advance()) {
            const Rectangle& rect = itr.retrieve();
            cout << endl;
            cout << rect.getTop() << " " << rect.getLeft() << " " << rect.getBottom() << " " << rect.getRight();
        }
    }

    return 0;
}
