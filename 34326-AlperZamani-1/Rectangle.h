#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
public:
    // Default constructor
    Rectangle();
    // Construct a rectangle
    Rectangle(int top, int left, int bottom, int right);

    // Accessor for private members
    int getTop() const;
    int getLeft() const;
    int getBottom() const;
    int getRight() const;

    // Mutators
    void setTop(int t);
    void setLeft(int l);
    void setBottom(int b);
    void setRight(int r);

    // Determines whether a point lies inside this rectangle
    bool contains(int x, int y) const;

    // Equality comparison operators
    bool operator==(const Rectangle& rect) const;
    bool operator!=(const Rectangle& rec1) const;

    // Private members
private:
    int Top;
    int Left;
    int Bottom;
    int Right;
};

#endif // RECTANGLE_H
