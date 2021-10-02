#include<stdio.h>

int main(){
    int a=9,b=3;
    int addition;
    int subtraction;
    int multiplication,division,modulus;

    printf("addition is : %d\n",addition);
    printf("subtraction is : %d\n",subtraction);
    printf("multiplication is : %d\n",multiplication);
    printf("division is : %d\n",division);
    printf("modulus is : %d\n",modulus);
    addition=a+b;
    subtraction=a-b;
    multiplication=a*b;
    division=a/b;
    modulus=a%b;

    printf("addition of two numbers %d,%d is : %d\n",a,b,addition);
    printf("subtraction of two numbers %d,%d is : %d\n",a,b,subtraction);
    printf("multiplication of two numbers %d,%d is : %d\n",a,b,multiplication);
    printf("division of two numbers %d,%d is : %d\n",a,b,division);
    printf("modulus of two numbers %d,%d is : %d\n",a,b,modulus);
    return 0;
}