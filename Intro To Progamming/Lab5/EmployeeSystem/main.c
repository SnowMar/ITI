#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define Up 72
#define Down 80
#define Enter 13
#define Exit 27
#define Backspace 8
#define EXTENDED_KEY -32
#define MAX_EMPLOYEES 1000

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

void drawMenu(int position) {
    COORD coord;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    coord.X = 40;

    coord.Y = 5;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 0 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("New   ");

    coord.Y = 10;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 1 ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("Display");

    coord.Y = 15;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 2 ? FOREGROUND_BLUE | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("Modify  ");

    coord.Y = 20;
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, position == 3 ? FOREGROUND_GREEN | BACKGROUND_RED : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("Exit  ");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void clearScreen() {
    system("cls");
}

int main() {
    char ch;
    int position = 0;
    int running = 1;
    int employeeCount = 0;

    Employee employees[MAX_EMPLOYEES];

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
            clearScreen();
            drawMenu(position);
        } else if (ch == Enter) {
            clearScreen();
            if (position == 0) {
                printf("New Option Selected. Press Backspace to return to the main menu.\n");
                printf("How many employees do you want to add? ");

                int newEmpCount = 0;
                scanf("%d", &newEmpCount);

                for (int i = 0; i < newEmpCount; i++) {
                    printf("Please Enter Employee ID: ");
                    scanf("%d", &employees[employeeCount].id);

                    getchar();
                    printf("Please Enter Employee Name: ");
                    scanf("%[^\n]s", employees[employeeCount].name);

                    printf("Please Enter Employee Age: ");
                    scanf("%d", &employees[employeeCount].age);

                    printf("Please Enter Employee Salary: ");
                    scanf("%f", &employees[employeeCount].salary);

                    employeeCount++;
                }

                printf("Employees added successfully! Press Backspace to return to the menu.\n");
                while (getch() != Backspace);
                clearScreen();
                drawMenu(position);
            } else if (position == 1) {
                printf("Display Option Selected. Press Backspace to return to the main menu.\n");

                if (employeeCount == 0) {
                    printf("No employees to display.\n");
                } else {
                    printf("\nEmployee List:\n");
                    printf("---------------------------------------------------\n");
                    printf("ID\tName\t\tAge\tSalary\n");
                    printf("---------------------------------------------------\n");
                    for (int i = 0; i < employeeCount; i++) {
                        printf("%d\t%-15s\t%d\t%.2f\n",
                               employees[i].id,
                               employees[i].name,
                               employees[i].age,
                               employees[i].salary);
                    }
                    printf("---------------------------------------------------\n");
                }

                printf("Press Backspace to return to the menu.\n");
                while (getch() != Backspace);
                clearScreen();
                drawMenu(position);
            } else if (position == 2) {
                printf("Modify Option Selected. Press Backspace to return to the main menu.\n");
                printf("Please enter the Employee ID to modify: ");

                int idToModify, found = 0;
                scanf("%d", &idToModify);

                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].id == idToModify) {
                        printf("Editing Employee ID %d\n", idToModify);
                        printf("Enter New Name: ");
                        getchar();
                        scanf("%[^\n]s", employees[i].name);

                        printf("Enter New Age: ");
                        scanf("%d", &employees[i].age);

                        printf("Enter New Salary: ");
                        scanf("%f", &employees[i].salary);

                        printf("Employee updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Employee with ID %d not found.\n", idToModify);
                }

                printf("Press Backspace to return to the menu.\n");
                while (getch() != Backspace);
                clearScreen();
                drawMenu(position);
            } else if (position == 3) {
                printf("Exiting... Bye!\n");
                running = 0;
            }
        }
    }
}