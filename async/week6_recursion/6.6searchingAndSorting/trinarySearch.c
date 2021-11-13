#include <stdio.h>

int trinarySeach(int *arr, int lo, int mid, int hi, int value)
{
    if (hi >= lo)
    {
        int loMid = lo + (mid - lo) / 2;
        int hiMid = mid + (hi - mid) / 2;

        if (arr[loMid] == value)
            return loMid;

        if (arr[hiMid] == value)
            return loMid;

        if (arr[loMid] > value)
            return trinarySeach(arr, lo, loMid, mid - 1, value);

        return trinarySeach(arr, mid + 1, hiMid, hi, value);
    }
    // Element not present.
    return -1;
}

int main()
{
    int array[] = {1, 4, 7, 9, 10, 11, 56, 69, 20};
    printf("binary search for %d: %d\n", 13, trinarySeach(array, 13, 0, 4, 8));
    return 0;
}