#include <stdio.h>

void insertionSort(int *a, int N)
{
    for (int i = 1; i < N; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {5, 3, 6, 2, 4};
    insertionSort(a, 5);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}