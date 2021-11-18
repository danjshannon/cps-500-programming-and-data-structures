#include <stdio.h>

int main()
{
    int x = 0;
    int z = 0;
    printf("Input a number x: \n");
    scanf("%d", &x);
    for (int y = 2; y < x; y++)
    {
        printf("y: %d, %d mod %d: %d\n", y, x, y, x % y);
        if (x % y == 0)
        {
            printf("%d is not a prime number.\n", x);
            z = 1;
            break;
        }
    }
    if (z == 0)
    {
        printf("%d is a prime number.\n", x);
    }
    return 0;
}