#include <stdio.h>
int main()
{
    int arr[2][2] = {12, 34, 56, 32};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}