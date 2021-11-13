# 6.5 Tail Recursion
## Recursion vs Iteration
- Generally, a recursive algorithm produces a slower than equivalent iterative algorithm
- This is due to the overhead of function calls pushing arguments and control values onto the stack
- we may also run out of room on the stack memory segment as each function uses a portion of the stack
  - This results in a stack overflow
  - Recursive solutions don't typically scale well.

## Tail Recursion
- One where every recursive call is the last thing done by the function before returning and thus produces the function's value
- the benefit of tail recursion is that there are compiler techniques that can replace tail recursion with iteration at the assembly level.
**GCD is a tail recursive algorithm**

## Transofrm to Tail Recursion
- Can we transform any of the existing algos to tail recursion


## Tail Factorial
```C
int factorial(int n, int total){
    if( n==0){
        return total;
    }
    return factorial(n-1,n*total);
}

factorial(5,1);
// must be called with 1 as a second parameter 

```