#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mealChoice;
    printf("Please Choose\n 1- Pizza \n 2- Burger \n 3- Koshary \n");
    scanf("%d", &mealChoice);

    switch (mealChoice) {
    case 1: {
        printf("Your Meal is Pizza\n");
        break;
    }
    case 2: {
        printf("Your Meal is Burger:\n");
        break;
    }
    case 3: {
        printf("Your Meal is Koshary\n");
        break;
    }
    default:
        printf("Kindly choose the right meal option \n");
    }
    return 0;
}
