#ifndef RECT_H
#define RECT_H


class Rect {

    private:
        Point ul;
        Point lr;
    public:
        Rect() : ul(), lr()
        { cout<<"At Rect Const.";}

        Rect(int x1, int y1, int x2, int y2) : ul(x1,y1), lr(x2,y2) { cout<<"At Rect Const."; }
        void draw() {
            rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY()) ;

        }
};

#endif
