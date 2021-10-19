#include <stdio.h>
int main()
{
    int userInput;
    printf("Enter an integer value: ");
    scanf("%d", &userInput);
    if (userInput > 5)
        printf("%d > 5\n", userInput);
    else
        printf("%d <= 5\n", userInput);
    return 0;
}

//a.out 16800