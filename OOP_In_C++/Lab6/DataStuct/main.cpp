#include <iostream>

using namespace std;

class Parent {
public:
    int x;
    Parent(int m) {
        x = m;
    }
};

class Child : protected Parent {
public:
    int y;
    Child(int m, int n) : Parent(m) {
        y = n;
    }
};

class GrandChild : public Child {

public:
    int z;
    GrandChild(int a, int b, int c) : Child(a, b) {
        z = c;
    }
};

int main() {
    GrandChild obj(3, 5, 7);
    //cout << "Value of x is: " << obj.x << endl;
    cout << "Value of y is: " << obj.y << endl;
    cout << "Value of z is: " << obj.z << endl;

    return 0;
}
