#include <stdio.h>

int main()
{
    char a_string[10] = "Hello";
    char b_string[10] = "Hello";
    if (b_string == a_string)
    {
        printf("the strings match!\n");
    }
    else
    {
        printf("this strings don't match!\n");
    }
    return 0;
}
