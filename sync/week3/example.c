#include <stdio.h>

int ArrayExample(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr++;

        arr--;
    }
    return 0;
}

int main()
{
    return 0;
}