#include <iostream>
#include <C:\Program Files\CodeBlocks\MinGW\include\graphics.h>
#include <conio.h>
using namespace std;

// Base class Paint
class Paint {
public:
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Paint() {}

    // Pure virtual function for drawing
    virtual void draw() = 0;
};

// Point class (no inheritance, utility class for coordinates)
class Point {
    int x;
    int y;

public:
    Point() : x(0), y(0) {}                  // Default constructor
    Point(int m, int n) : x(m), y(n) {}      // Parameterized constructor

    void setX(int m) { x = m; }
    void setY(int n) { y = n; }

    int getX() { return x; }
    int getY() { return y; }
};

// Line class inheriting from Paint
class Line : public Paint {
    Point start;
    Point end;

public:
    Line() : start(), end() {
        cout << "At Line Default Constructor\n";
    }
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {
        cout << "At Line Parameterized Constructor\n";
    }

    void draw() override {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

// Rect class inheriting from Paint
class Rect : public Paint {
    Point ul; // Upper-left corner
    Point lr; // Lower-right corner

public:
    Rect() : ul(), lr() {
        cout << "At Rect Constructor\n";
    }
    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {
        cout << "At Rect Constructor\n";
    }

    void draw() override {
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

// Circle class inheriting from Paint
class Circle : public Paint {
    Point center;
    int radius;

public:
    Circle() : center(), radius(0) {
        cout << "At Circle Constructor\n";
    }
    Circle(int m, int n, int r) : center(m, n), radius(r) {
        cout << "At Circle Constructor\n";
    }

    void draw() override {
        circle(center.getX(), center.getY(), radius);
    }
};

// Picture class to manage all Paint objects
class Picture {
    int shapeCount;     // Total number of shapes
    Paint** shapes;     // Array of pointers to Paint objects

public:
    Picture() : shapeCount(0), shapes() {}

    Picture(int count, Paint** pShapes) : shapeCount(count), shapes(pShapes) {}

    ~Picture() {
        // Clean up dynamically allocated objects
        for (int i = 0; i < shapeCount; i++) {
            delete shapes[i];
        }
        delete[] shapes;
    }

    // Draw all shapes
    void paint() {
        for (int i = 0; i < shapeCount; i++) {
            shapes[i]->draw();
        }
    }
};

// Main function
int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Dynamically create shapes
    Paint* shapes[4];
    shapes[0] = new Line(50, 50, 150, 150);
    shapes[1] = new Rect(200, 200, 300, 300);
    shapes[2] = new Circle(400, 400, 50);
    shapes[3] = new Line(400, 50, 500, 150);

    // Create a picture and draw all shapes
    Picture picture(4, shapes);
    picture.paint();

    getch();     // Wait for user input
    closegraph(); // Close graphics mode
    return 0;
}
