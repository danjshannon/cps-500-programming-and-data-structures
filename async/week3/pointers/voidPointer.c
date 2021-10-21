#include <stdio.h>

int main()
{
    int x = 10;
    char ch = 'A';
    void *gp = &x;
    printf("Generic pointer points to an integer = %d\n", *(int*)gp);
    gp = &ch;
    printf("Generic pointer points to an integer = %d\n", *(char*)gp);
    return 0;
}

//The second line should be 'A'... Check with office hours