#include <stdio.h>

int globalVar;
runForLoopExample()
{
}

int main()
{
    int userInput;
    char userChar;
    int funcRet;
    int counter;
    printf("Enter an integer value: \n");
    funcRet = scanf("%d", &userInput);
    if (funcRet == 1)
    {

        if (userInput > 5)
        {
            printf("The input was > 5\n");
        }
        else
            printf("The input was < 5\n");
    }
    else
        printf("User input did not meet expectations.\n");

    printf("Enter an character value: \n");
    funcRet = scanf("%s", &userChar);
    switch (userChar)
    {
    case 'a':
        //printf("User entered a vowel (%c).\n", userChar);
        //break;
    case 'e':
        //printf("User entered a vowel (%c).\n", userChar);
        //break;
    case 'i':
        //printf("User entered a vowel (%c).\n", userChar);
        //break;
    case 'o':
        //printf("User entered a vowel (%c).\n", userChar);
        //break;
    case 'u':
        printf("User entered a vowel (%c).\n", userChar);
        break;
    default:
        printf("User entered a consonant (%c).\n", userChar);
    }

    printf("Enter an integer value: \n");
    funcRet = scanf("%d", &userInput);
    counter = 1;
    while (counter < userInput)
    {
        printf("While counter is %d\n", counter++);
    }

    do
    {
        printf("Do while counter = %d.\n", --counter);
    } while (counter > 0);

    for (counter = 0; counter <= userInput; ++counter)
    {
        if (counter > 2 && counter < 5)
        {
            continue;
        }
        printf("for loop counter =%d.\n", counter);
        if (counter > 3)
            break; //breaking out of loop because...
    }
    printf("After for loop counter = %d.\n", counter);
    return 0;
}