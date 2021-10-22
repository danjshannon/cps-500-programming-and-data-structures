#include <stdio.h>
int main()
{
    int A[5] = {5, 10, 3, 90, 51};
    int min = A[0];             //set min to first element
    for (int i = 1; i < 5; i++) //start at i=1 since we've "checked" A[0]
    {
        if (min > A[i])
        {
            min = A[i];
        }
        printf("A[%d] = %d\n", i, A[i]);
    }
    printf("Min of A = %d\n", min);
    return 0;
}