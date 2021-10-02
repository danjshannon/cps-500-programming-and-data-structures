#include<stdio.h>

int main(){
    int a=9,b=3;
    int addition;
    int subtraction;
    int multiplication,division,modulus;

    addition=a+b;
    subtraction=a-b;
    multiplication=a*b;
    division=a/b;
    modulus=a%b;

    printf("addition of two numbers a,b is : %d\n",addition);
    printf("subtraction of two numbers a,b is : %d\n",subtraction);
    printf("multiplication of two numbers a,b is : %d\n",multiplication);
    printf("division of two numbers a,b is : %d\n",division);
    printf("modulus of two numbers a,b is : %d\n",modulus);
    return 0;
}