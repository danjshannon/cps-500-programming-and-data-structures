#include <stdio.h>

#define PI 3.1419265359

int main(){
    double a =-1.0;
    double b =-1.0;

    printf("Enter the first axis:\n");
    scanf("%lf",&a);
    printf("Enter the second axis:\n");
    scanf("%lf",&b);
    double area =PI*a*b;
    printf("The area of the ellipse is: %2.10f\n",area);
}