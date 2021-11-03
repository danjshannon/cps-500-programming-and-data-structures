#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp1 = arr[j];
                int temp2 = arr[j + 1];
                arr[j] = temp2;
                arr[j + 1] = temp1;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    int a[] = {5, 3, 6, 2, 4};
    bubbleSort(a, 5);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}