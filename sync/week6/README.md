# Week 6 Recursion
- A function that calls itself
- Each iteration of the function maintains is own environement
- most important - base case
- if unclear, user pencil and paper to map each call

- slower than loops
- Can use loops instead of recursion and vice versa
- tail recursion
  - recursion is the last call in the function.


## Factorial
- n!=n\*(n-1)\*(n-2)\*...\*1
```C
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n * factorial(n-1);
}
```
- n<0 will infinitley recurse (until your int flips to positive lol)

## GCD
- Greatest Common Divisor

```C
int gcd(int x, int y ){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
```

## Fib
- series of numbers where each is the sum of the previous 2 numbers

```C
int fib(int i){
    if(i==1||i==2){
        return 1;
    }
    return fib(i-1) + fib(i-2);
}
```

## Seaching and Sorting
- Binary Search
- Merge Sort
- Quick Sort

## Week 6 Assignment
- use recursion for the problems
- Question 3 hint
  - Figure out how you want to attack this.
  - I can do that in a loop
    - do it in a loop, 
    - what's inside is the recursive function,
    - loop conditions are the base case
- Question 2
  - powers are only &ge;0

- Quiz around week 9
  - recursion onward
