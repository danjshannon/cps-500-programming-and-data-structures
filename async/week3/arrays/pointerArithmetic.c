#include <stdio.h>
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr = array; //Recall array = &array[0] - a pointer to the address of the array!
    while (ptr != &array[5])
    {
        printf("%d\n", *ptr);
        ptr++;
    }
    return 0;
}