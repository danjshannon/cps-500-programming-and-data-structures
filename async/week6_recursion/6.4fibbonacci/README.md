# 6.4 Fibonacci Numbers
- A series of integers such taht each number is the sum of the previous two numbers in the sequence
- 1,1,2,3,5,8,13,21,34,55,89,144...
```C
int fib(int i){
    if( i==1 || i==2 ){
        return 1;
    }
    return fib(i-1) + fib(i-2);
}
```
## Fibonacci Runtime?
- We can take an upper and lower bound
- The depth of the tree will be n-1 since on the left-most branch we subtract 1 at every step..
- The right-most branch of the tree will be the shortest since it subtracts by 2. Each step will have n/2-1 levels
- Each full level will have 2<sup>k</sup> nodes where k is the level.
- Recursive runtime is between
  - **&radic;(2)<sup>n</sup>**
  - **2<sup>n</sup>**
- Precise runtime is &phi;<sup>n</sup>
  - &phi;~=1.618 (golden ratio)

## Iterative Fibonacci
```C
int iterativeFib(int n){
    int f1=1;
    int f2=2;
    
    for(int i=2;i<n;i++){
        int temp = f1+f2;
        f1=f2;
        temp=f2;
    }
}
```