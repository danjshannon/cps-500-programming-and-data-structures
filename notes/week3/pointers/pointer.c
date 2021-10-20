#include <stdio.h>
//What is the output?

//The number the user inputs
int main()
{
    int num;
    int *pnum;
    pnum = &num;
    printf("\n Enter the number :");
    scanf("%d", &num);
    printf("\n The number that was entered is %d\n", *pnum);
    return 0;
}