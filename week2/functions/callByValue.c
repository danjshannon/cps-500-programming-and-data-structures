#include <stdio.h>
//int f(int x);

int f(int x)
{
    printf("initial x: %d\n", x);
    x++;
    printf("incremented x: %d\n", x);
    return x;
}

int main()
{
    int y = 0;
    y = f(y);
    printf("y after function call: %d\n", y);
    return 0;
}