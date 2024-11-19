#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[3][4];
    int rowSum[3] = {0};
    int colavg[4] = {0};

    for(int i=0; i < 3; i++){
            printf("You are in the row number: %d \n", i+1);
        for(int j=0; j < 4; j++){
            printf("\n Please enter the number in the column number: %d \n", j+1);
            scanf("%d", &arr[i][j]);
            rowSum[i] += arr[i][j];
            colavg[j] += arr[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        printf("\n\nRow Sum %d: %d\n", i+1, rowSum[i]);
        }

    for(int j =0; j < 4; j++){
        int avg = colavg[j] / 3;
        printf("\nAvg of column number %d: %d \n", j+1, avg);
    }



    return 0;
}
