#include <stdio.h>

int binarySearch(int *array, int value, int lo, int hi)
{
    if (lo > hi)
    {
        return -1;
    }
    int middle = lo + (hi - lo) / 2;
    if (array[middle] == value)
    {
        return middle;
    }
    else if (array[middle] < value)
    {
        return binarySearch(array, value, middle + 1, hi);
    }
    else
    {
        return binarySearch(array, value, lo, middle - 1);
    }
}

int main()
{
    int array[] = {1, 4, 7, 9, 10, 11, 56, 69, 20};
    printf("binary search for %d: %d\n", 13, binarySearch(array, 13, 0, 8));
    return 0;
}