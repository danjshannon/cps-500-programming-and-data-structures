#include <stdio.h>

int main(){
    int number1=0;
    int number2=0;
    printf("Enter two integers: \n");
    scanf("%d %d",&number1,&number2);
    if(number1>number2){
        printf("Result: %d > %d\n",number1,number2);
    }else if( number1<number2) {
        printf("Result %d < %d\n",number1,number2);
    }else{
        printf("Result: %d = %d\n",number1,number2);
    }
    return 0;

}