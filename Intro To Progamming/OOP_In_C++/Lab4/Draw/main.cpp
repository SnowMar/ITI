#include <iostream>
#include "C:\Program Files\CodeBlocks\MinGW\include\graphics.h"

using namespace std;

class Point {
    int x;
    int y;

public:
    // Constructors
    Point() : x(0), y(0) {} // Default constructor
    Point(int m, int n) : x(m), y(n) {} // Parameterized constructor

    // Setter functions
    void setX(int m) { x = m; }
    void setY(int n) { y = n; }

    // Getter functions
    int getX() { return x; }
    int getY() { return y; }
};

class Line {
    Point start;
    Point end;

public:
    // Default Constructor
    Line() : start(), end() {
        cout << "At Line Default Constructor\n";
    }

    // Parameterized Constructor
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {
        cout << "At Line Parameterized Constructor\n";
    }

    // Draw function to draw the line
    void draw() {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Create and draw lines
    Line lArr[2] = {Line(420, 50, 300, 300), Line(40, 500, 500, 400)};

    lArr[0].draw(); // Draw the first line
    lArr[1].draw(); // Draw the second line

    getch(); // Wait for user input before closing
    closegraph(); // Close graphics mode
    return 0;
}
