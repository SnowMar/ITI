#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

#define Up 72
#define Down 80
#define Enter 13
#define Backspace 8
#define EXTENDED_KEY -32

#define MAX_EMPLOYEES 1000

class Employee {
private:
    int id;
    string name;
    int age;
    float salary;

public:
    void setData(int empId, string empName, int empAge, float empSalary) {
        id = empId;
        name = empName;
        age = empAge;
        salary = empSalary;
    }

    void displayData() {
        cout << id << "\t" << name << "\t" << age << "\t" << salary << endl;
    }

    int getId() {
        return id;
    }
};

class EmployeeStack {
private:
    int top;
    Employee employees[MAX_EMPLOYEES];

public:
    EmployeeStack() : top(-1) {}


    void push(Employee emp){
        if(top== MAX_EMPLOYEES -1){
            cout<<"\nStack Is Full\n";
        }
        else{
            employees[++top] = emp;
            cout << "Employee added successfully!\n";
        }
    }


    void pop() {
        if (top == -1) {
            cout << "\nStack is empty.\n";
        } else {
            cout << "Removed Employee ID: " << employees[top].getId() << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "No employees to display. The stack is empty.\n";
        } else {
            cout << "\nEmployee List:\n";
            cout << "---------------------------------------------------\n";
            cout << "ID\tName\t\tAge\tSalary\n";
            cout << "---------------------------------------------------\n";
            for (int i = top; i >= 0; i--) {
                employees[i].displayData();
            }
            cout << "---------------------------------------------------\n";
        }
    }
};

void drawMenu(int position) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = 40;

    coord.Y = 5;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 0 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "Push";

    coord.Y = 10;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 1 ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "Display";

    coord.Y = 15;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 2 ? FOREGROUND_BLUE | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "Pop";

    coord.Y = 20;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 3 ? FOREGROUND_GREEN | BACKGROUND_RED : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "Exit";

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {
    char ch;
    int position = 0;
    bool running = true;
    EmployeeStack s;

    drawMenu(position);

    while (running) {
        ch = getch();

        if (ch == EXTENDED_KEY) {
            ch = getch();
            if (ch == Up) {
                position = (position == 0) ? 3 : position - 1;
            } else if (ch == Down) {
                position = (position == 3) ? 0 : position + 1;
            }
            system("cls");
            drawMenu(position);
        } else if (ch == Enter) {
            system("cls");
            if (position == 0) {
                cout << "New Option Selected. Press Backspace to return to the main menu.\n";
                Employee emp;
                int empId, empAge;
                string empName;
                float empSalary;

                cout << "Please Enter Employee ID: ";
                cin >> empId;
                cin.ignore();

                cout << "Please Enter Employee Name: ";
                getline(cin, empName);

                cout << "Please Enter Employee Age: ";
                cin >> empAge;

                cout << "Please Enter Employee Salary: ";
                cin >> empSalary;

                emp.setData(empId, empName, empAge, empSalary);
                s.push(emp);

                cout << "Press Backspace to return to the menu.\n";
                while (getch() != Backspace);
                system("cls");
                drawMenu(position);
            } else if (position == 1) {
                cout << "Display Option Selected. Press Backspace to return to the main menu.\n\n";
                s.display();
                cout << "Press Backspace to return to the menu.\n";
                while (getch() != Backspace);
                system("cls");
                drawMenu(position);
            } else if (position == 2) {
                cout << "Pop Option Selected. Press Backspace to return to the main menu.\n";
                s.pop();
                cout << "Press Backspace to return to the menu.\n";
                while (getch() != Backspace);
                system("cls");
                drawMenu(position);
            } else if (position == 3) {
                cout << "Exiting... Bye!\n";
                running = false;
            }
        }
    }

    return 0;
}
