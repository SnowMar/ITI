#include <stdio.h>
#include <stdlib.h>


int main() {

    for (int firstLoop = 1; firstLoop <= 10; firstLoop++) {

        printf("Multiplication Table for %d:\n", firstLoop);
        for (int secondLoop = 1; secondLoop <= 10; secondLoop++) {
            printf("%d x %d = %d\n", firstLoop, secondLoop, firstLoop * secondLoop);
        }

        if (firstLoop < 10) {
            printf("\n*****************************\n\n");
        }
    }

    printf("\n\nEnd of ascending\n\n");

        for (int firstLoop = 10; firstLoop >= 1; firstLoop--) {

        printf("Multiplication Table for %d:\n", firstLoop);
        for (int secondLoop = 10; secondLoop >= 1; secondLoop--) {
            printf("%d x %d = %d\n", firstLoop, secondLoop, firstLoop * secondLoop);
        }

        if (firstLoop > 10) {
            printf("\n*****************************\n\n");
        }
    }

    printf("\n\nEnd of descending\n\n");

    return 0;
}
