#include "Rectangle.h"

// Default constructor initialises to 0
Rectangle::Rectangle() : Top(0), Left(0), Bottom(0), Right(0) {}

// Construct a rectangle
Rectangle::Rectangle(int top, int left, const int bottom, int right)
    : Top(top), Left(left), Bottom(bottom), Right(right) {

}

// Accessors
    int Rectangle::getTop() const {
        return Top;
    }
    int Rectangle::getLeft() const {
        return Left;
    }
    int Rectangle::getBottom() const {
        return Bottom;
    }
    int Rectangle::getRight() const {
        return Right;
    }

    // Mutators
    void Rectangle::setTop(int t) {
        Top    = t;
    }
    void Rectangle::setLeft(int l) {
        Left   = l;
    }
    void Rectangle::setBottom(int b) {
        Bottom = b;
    }
    void Rectangle::setRight(int r) {
        Right  = r;
    }

// Checks if this rectangle contains a point
bool Rectangle::contains(int x, int y) const {

    return (x >= Left && x < Right && y >= Top && y < Bottom);

}

// Equality operators
bool Rectangle::operator==(const Rectangle& rect) const {

    return Top == rect.Top && Left == rect.Left &&
           Bottom == rect.Bottom && Right == rect.Right;

}
bool Rectangle::operator!=(const Rectangle& rec1) const {

    return !(*this == rec1);
}
