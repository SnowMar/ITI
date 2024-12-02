#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Up 72
#define Down 80
#define Right_KEY 77
#define Left_KEY 75
#define EXTENDED_KEY -32
#define Backspace 8
#define DELETE_KEY 83
#define INSERT_KEY 82
#define MAX_Chars 100

int main() {
    char streamstring[MAX_Chars] = "";
    int cursorPos = 0;
    int length = 0;
    int insertMode = 1;
    int running = 1;

    printf("Line Editor (Press ESC to exit)\n");
    printf("Start typing:\n");

    while (running) {
        char ch = getch();

        if (ch == 27) {
            running = 0;
        } else if (ch == Backspace) {
            if (cursorPos > 0) {
                for (int i = cursorPos - 1; i < length - 1; i++) {
                    streamstring[i] = streamstring[i + 1];
                }
                streamstring[--length] = '\0';
                cursorPos--;
            }
        } else if (ch == EXTENDED_KEY) {
            ch = getch();

            if (ch == Left_KEY && cursorPos > 0) {
                cursorPos--;
            } else if (ch == Right_KEY && cursorPos < length) {
                cursorPos++;
            } else if (ch == DELETE_KEY) {
                if (cursorPos < length) {
                    for (int i = cursorPos; i < length - 1; i++) {
                        streamstring[i] = streamstring[i + 1];
                    }
                    streamstring[--length] = '\0';
                }
            } else if (ch == INSERT_KEY) {
                insertMode = !insertMode;
            }
        } else if (length < MAX_Chars - 1) {
            if (insertMode) {
                for (int i = length; i > cursorPos; i--) {
                    streamstring[i] = streamstring[i - 1];
                }
                streamstring[cursorPos] = ch;
                streamstring[++length] = '\0';
            } else {
                if (cursorPos < length) {
                    streamstring[cursorPos] = ch;
                } else {
                    streamstring[cursorPos] = ch;
                    streamstring[++length] = '\0';
                }
            }
            cursorPos++;
        }

        system("cls");
        printf("Start typing:\n");
        printf("%s\n", streamstring);

        for (int i = 0; i < cursorPos; i++) {
            printf(" ");
        }
        printf("^");
    }

    return 0;
}
