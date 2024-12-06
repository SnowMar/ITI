#include <iostream>
using namespace std;

class Stack {
private:
    int* data;      // Pointer to the stack array
    int top;        // Index of the top element
    int capacity;   // Capacity of the stack

    // Static variables to count constructor and destructor calls
    static int constructorCount;
    static int destructorCount;

public:
    // Default constructor
    Stack(int size = 5) : capacity(size), top(-1) {
        data = new int[capacity];
        constructorCount++;
        cout << "Default Constructor called. Total Constructors: " << constructorCount << endl;
    }

    // Copy constructor
    Stack(const Stack& other) {
        capacity = other.capacity;
        top = other.top;
        data = new int[capacity];
        for (int i = 0; i <= top; ++i) {
            data[i] = other.data[i];
        }
        constructorCount++;
        cout << "Copy Constructor called. Total Constructors: " << constructorCount << endl;
    }

    // Destructor
    ~Stack() {
        delete[] data;
        destructorCount++;
        cout << "Destructor called. Total Destructors: " << destructorCount << endl;
    }

    // Push function
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = value;
    }

    // Pop function
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        --top;
    }

    // Display function
    void display() const {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // View content by reference
    static void viewContentByReference(const Stack& stack) {
        cout << "Viewing content by reference:" << endl;
        stack.display();
    }

    // View content by value without copy constructor
    static void viewContentByValueNoCopy(Stack stack) {
        cout << "Viewing content by value without copy constructor:" << endl;
        stack.display();
    }

    // View content by value with copy constructor
    static void viewContentByValueWithCopy(Stack stack) {
        cout << "Viewing content by value with copy constructor:" << endl;
        stack.display();
    }

    // Static function to print constructor and destructor calls
    static void printCounts() {
        cout << "Total Constructors: " << constructorCount << endl;
        cout << "Total Destructors: " << destructorCount << endl;
    }
};

// Initialize static members
int Stack::constructorCount = 0;
int Stack::destructorCount = 0;

// Main function
int main() {
    // Create a stack
    Stack stack1(5);
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    // View content by reference
    Stack::viewContentByReference(stack1);

    // View content by value without copy constructor
    Stack::viewContentByValueNoCopy(stack1);

    // View content by value with copy constructor
    Stack::viewContentByValueWithCopy(stack1);

    // Print constructor and destructor counts
    Stack::printCounts();

    return 0;
}
