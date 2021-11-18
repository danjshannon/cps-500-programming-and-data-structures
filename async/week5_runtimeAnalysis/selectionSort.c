#include <stdio.h>

void selectionSort(int *a, int N)
{
    int minJ, minVal;
    for (int i = 0; i < N - 1; i++)
    {

        //find a minJ &isin; {1,...,n-} such that:
        // a[minJ]=min{a[j]:i<=j<=n-1}
        minJ = i;
        minVal = a[i];
        for (int j = i + 1; j <= N - 1; j++)
        {
            if (a[j] < minVal)
            {
                minJ = j;
                minVal = a[j];
            }
        }
        //swap the values of a[i] and a[minJ]
        a[minJ] = a[i];
        a[i] = minVal;
    }
}

int main()
{
    int a[] = {5, 3, 6, 2, 4};
    selectionSort(a, 5);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}