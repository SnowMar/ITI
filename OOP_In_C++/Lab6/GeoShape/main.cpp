#include <iostream>
using namespace std;

class GeoShape {
protected:
    float dim1;
    float dim2;

public:
    GeoShape() { dim1 = dim2 = 0; }
    GeoShape(float x) { dim1 = dim2 = x; }
    GeoShape(float x, float y) {
        dim1 = x;
        dim2 = y;
    }

    void setDim1(float x) { dim1 = x; }
    void setDim2(float x) { dim2 = x; }

    float getDim1() { return dim1; }
    float getDim2() { return dim2; }

    virtual float calculateArea() { return 0; }
};

class SquarePublic : public GeoShape {
public:
    SquarePublic(float side) : GeoShape(side, side) {}

    float calculateArea() {
        return dim1 * dim2;
    }
};

class Circle : protected GeoShape {
public:
    Circle(float radius) : GeoShape(radius, radius) {}

    void setRadius(float radius) {
        dim1 = dim2 = radius;
    }

    float getRadius() { return dim1; }

    float calculateArea() {
        return 3.14159 * dim1 * dim1;
    }
};

class Square : protected GeoShape {
public:
    Square(float side) : GeoShape(side, side) {}

    void setSide(float side) {
        dim1 = dim2 = side;
    }

    float getSide() { return dim1; }

    float calculateArea() {
        return dim1 * dim2;
    }
};

int main() {
    cout << "=== Public Inheritance ===" << endl;
    SquarePublic sqPublic(5);
    cout << "Original Square Area: " << sqPublic.calculateArea() << endl;

    sqPublic.setDim1(5);
    sqPublic.setDim2(10);
    cout << "Modified Square Area (Constraint Violated): " << sqPublic.calculateArea() << endl;

    cout << "\n=== Protected Inheritance with Special Setter Methods ===" << endl;

    Circle c(5);
    cout << "Original Circle Area: " << c.calculateArea() << endl;
    c.setRadius(10);
    cout << "Updated Circle Area: " << c.calculateArea() << endl;

    Square s(4);
    cout << "Original Square Area: " << s.calculateArea() << endl;
    s.setSide(8);
    cout << "Updated Square Area: " << s.calculateArea() << endl;

    return 0;
}
