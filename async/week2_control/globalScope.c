#include <stdio.h>
int a;
int main()
{
    a = 5;
    return a;
}
void funct(int x)
{
    x += a;
}