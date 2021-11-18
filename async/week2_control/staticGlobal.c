#include <stdio.h>

static void func(void)
{
    printf("func called:\n");
}

static void main(void)
{
    func(); //this will cause a compile time error.
    // it does
}