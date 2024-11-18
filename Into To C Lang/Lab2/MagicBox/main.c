#include <stdio.h>

int main() {
    int n;

    printf("Enter an odd number: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Only odd numbers are allowed.\n");
        return 0;
    }

    int row = 0, col = n / 2;
    int num = 1;

    while (num <= n * n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == row && j == col) {
                    printf("%4d", num);
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
        printf("\n");

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (num % n == 0) {
            newRow = (row + 1) % n;
            newCol = col;
        }

        row = newRow;
        col = newCol;
        num++;
    }

    return 0;
}
