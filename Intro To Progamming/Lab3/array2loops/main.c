#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tarray[10];
    int i;
    int j;

    for(i=0; i < 10; i++){
        printf("Please fill the array: ");
        scanf("%d", &tarray[i]);
    }

    for(j = 0; j < 10; j++)
        printf("%d", tarray[j]);
    return 0;
}
