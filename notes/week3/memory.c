#include <stdio.h>

int N = 10;
int max(int x, int y)
{
    int z = x;
    if (x < y)
    {
        z = y;
    }
    return z;
}

int main()
{
    int a = 5;
    printf("Max: %d", max(a, N));
}