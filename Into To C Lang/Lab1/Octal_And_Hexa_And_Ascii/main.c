#include <stdio.h>
#include <stdlib.h>

int main()
{
    char y;
    int number;
    printf("Enter Your Char: \n");
    scanf("%c", &y);
    printf("%d \t ",y);
    printf("Enter Your Number: \n");
    scanf("%d", &number);
    printf("%x\t %o\n",number,number);

    return 0;
}
