#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define Up 72
#define Down 80

void clscreen() {
    system("cls");
}

void data(int position) {
    COORD coord;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    coord.X = 40;
    coord.Y = 5;
    SetConsoleCursorPosition(hConsole, coord);
    if (position == 0) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    printf("New   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    coord.Y = 10;
    SetConsoleCursorPosition(hConsole, coord);
    if (position == 1) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    printf("Display");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    coord.Y = 15;
    SetConsoleCursorPosition(hConsole, coord);
    if (position == 2) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    printf("Exit  ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {

    char ch;
    int position = 0;

    data(position);
    while (1) {
        ch = getch();
        if (ch == 0 || ch == 224) {
            ch = getch();
            if (ch == 72) {
                if (position > 0) {
                    position--;
                }else{
                    position = 2;
                }
            } else if (ch == 80) {
                if (position < 2) {
                    position++;

                }else{
                    position = 0;
                }
            }
            clscreen();
            data(position);
        }
    }

    return 0;
}
