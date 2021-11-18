# Week 1: Introduction
- [Home](https://github.com/danjshannon/cps-500-programming-and-data-structures#cps-500-data-structures)
- [1.1 Hello World](#11-hello-world)
- [1.2 Operators](#12-Operators)
## 1.1 Hello World
[top](#week-1-introduction)
```C
// this is a first program in C.
#include <stdio.h>

int main() {
	printf("Hello World!\n");
	return 0;
}
```
- [first.c](./first.c)

## 1.2 Operators
[top](#week-1-introduction)
```C
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
```
[operators.c](./operators.c)
