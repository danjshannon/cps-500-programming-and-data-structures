#include <stdio.h>

float square(float x);

int main(void)
{
    float m = 1.0;
    float n = 1.0;

    printf("\nEnter some number for finding square \n");
    scanf("%f", &m);
    n = square(m);
    printf("\nSquare of the gieven number %2.3f is %2.3f\n", m, n);
}

float square(float x)
{
    x *= x;
    return x;
}