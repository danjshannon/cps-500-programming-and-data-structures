#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = malloc(100 * sizeof(int));
    x = NULL;
    printf("%d\n", x);
    return 0;
}