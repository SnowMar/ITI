#include <iostream>
using namespace std;

class Complex {
    int real;
    int imag;

public:
    void setRealData(int r) {
        real = r;
    }

    int getRealData() {
        return real;
    }

    void setImgData(int i) {
        imag = i;
    }

    int getImgData() {
        return imag;
    }

    void display() {
        if (real == 0 && imag == 0) {
            cout << "No Data" << endl;
        } else if (real == 0) {
            cout << imag << "j" << endl;
        } else if (imag == 0) {
            cout << real << endl;
        } else if (imag > 0) {
            cout << real << " + " << imag << "j" << endl;
        } else {
            cout << real << " - " << -imag << "j" << endl;
        }
    }

    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    Complex subtract(Complex c2) {
        Complex result;
        result.real = real - c2.real;
        result.imag = imag - c2.imag;
        return result;
    }
};

void swapByValue(Complex a, Complex b) {
    Complex temp = a;
    a = b;
    b = temp;
}

void swapByAddress(Complex *a, Complex *b) {
    Complex temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(Complex &a, Complex &b) {
    Complex temp = a;
    a = b;
    b = temp;
}

int main() {
    Complex myComp1, myComp2, resultComp;

    cout << "Enter real number: ";
    int r1;
    cin >> r1;
    myComp1.setRealData(r1);

    cout << "Enter imaginary number: ";
    int i1;
    cin >> i1;
    myComp1.setImgData(i1);

    cout << "Enter 2nd real number: ";
    int r2;
    cin >> r2;
    myComp2.setRealData(r2);

    cout << "Enter 2nd imaginary number: ";
    int i2;
    cin >> i2;
    myComp2.setImgData(i2);

    cout << "\nFirst Complex Number: ";
    myComp1.display();
    cout << "Second Complex Number: ";
    myComp2.display();

    resultComp = myComp1.add(myComp2);
    cout << "Addition Result: ";
    resultComp.display();

    resultComp = myComp1.subtract(myComp2);
    cout << "Subtraction Result: ";
    resultComp.display();

    Complex a, b;
    a.setRealData(1);
    a.setImgData(2);
    b.setRealData(3);
    b.setImgData(4);

    cout << "\nBefore Swap:" << endl;
    cout << "A: ";
    a.display();
    cout << "B: ";
    b.display();

    swapByReference(a, b);

    cout << "After Swap:" << endl;
    cout << "A: ";
    a.display();
    cout << "B: ";
    b.display();

    cout<<"=============================================================="<<endl;
    swapByValue(a, b);
    cout << "After swapByValue:" << endl;
    cout << "A: ";
    a.display();
    cout << "B: ";
    b.display();

    cout<<"=============================================================="<<endl;
    swapByAddress(&a, &b);
    cout << "After swapByAddress:" << endl;
    cout << "A: ";
    a.display();
    cout << "B: ";
    b.display();

    Complex *ptr1 = new Complex();
    Complex *ptr2 = new Complex();

    ptr1->setRealData(5);
    ptr1->setImgData(6);
    ptr2->setRealData(7);
    ptr2->setImgData(8);

    cout << "\nDynamically Allocated Complex Numbers:" << endl;
    ptr1->display();
    ptr2->display();

    delete ptr1;
    delete ptr2;

    return 0;
}
