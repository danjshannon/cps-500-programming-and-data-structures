#include <stdio.h>

//do not use goto lol

int main(){
    even:
    printf("the number is even.\n");
    if (n%2==0){
        goto even;
    }
}