#include <stdio.h>
//#include <conio.h>

int main()
{
    int n;
    int arr[20];
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nArr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nThe array elements are:");
    for (int i = 0; i < n; ++i)
    {
        printf("\nArr[%d] = %d\t", i, arr[i]);
    }
    return 0;
}