#include <stdio.h>

int main() {
    int receivedNumber, sum = 0;

do{
    printf("please enter your number : ");
    scanf("%d", &receivedNumber);

    sum = sum + receivedNumber;
    printf("%d \n", sum);
}while(sum < 100);

    return 0;
}




/*
    for(receivedNumber <= 100; receivedNumber + incremental;){
        printf("please enter your number : ");
        int incremental = scanf("&d", &receivedNumber);

    }
    if (receivedNumber <= 100){
        printf("please enter your number : ");
        scanf("&d", &receivedNumber);
    }
    else if(receivedNumber > 100){
            printf("Test");

    }
*/

