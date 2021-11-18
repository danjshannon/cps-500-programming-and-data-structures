#include <stdio.h>
void PrintArrayFlat(int *A, int countA, int breakLine)
{
    printf("{ ");
    for (int a = 0; a < countA; a++)
    {
        printf("%d ", A[a]);
    }
    printf("}");
    if (breakLine == 1)
    {
        printf("\n");
    }
}

int main() {}