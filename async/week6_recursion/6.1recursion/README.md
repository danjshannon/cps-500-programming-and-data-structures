# 6.1 Recursion
- Involves a function calling itself.

## Introduction to Recursion
- A recursive method is a method that calls itself.

## Simple Example
- consider the following:
```C
void printRange(int n){
    if(n<1){
        return;      // base case
    }
    printRange(n-1); // recursive case
    printf("%d,",n);
}
```

## A recursive method
1. **Base Case** We are unable to subdivide the problem any thurther and need to compute the result of the problem at hand.
  - make it stop
2. **Recursive Case** We can further subdivide the problem and may have logic that details how to combine the result from the smaller problems.
  - continue recursing

## Why Recursion?
- some algorithms are simpler to write and read using recursive functions
- compared with iteration
  - Generally slower than loops
  - Everything that can be done with recursion can be done with iteration and vice versa

## Steps to Solve
1. The base-case question.
  - **Is there a nonrecursive way out of the cuntion and does the routine work correctly for this "base" case?**
2. The smaller-caller question
  - **Does each recursive call to the function involve a smaller case of the original problem, leading inescapably to the base case?**
3. The general-case question:
  - **Assuming that the recursive call(s) work(s) correctly, does the whole funciton work correctly?**

## Infinite Recursion
- Mistakes in the base case can lead to infinite recursion
- This is similar to infinite loop, but in this case it will eventually crash the program
  - Due to stack memory segment overflow