# Runtime Analysis

## How to measure algorithm speed
- **option 1** implement the algorithm and instrument to measure how long it takes.
  - would do this for multiple input sizes.
  - There are a lot of possible inputs/
  - Time differs based on a lot of variables - ram, cpu, other programs running
## Measure algorithm growth
- **option 2** Mathematically measure the runtime of an algorithm as a function of the size of the input.
  - n: n&isin;N
  - Finding precise funtion is hard, estimate usually good enough.
## Striaght-line code
- **straight-line** code is code that meets all of the following criteria.
  - contains no loops
  - contains no recursion
  - contains no function calls to non-straight-line code
- We call this constant time: Regardless of how large the input becomes, the time to execute this won't change.
### Examples
**straight-line** code examples:
```C
int a=5;
if(b<0){
    a+=5;
}
int min=min(5,10);
```

**non-straight-line** code examples:
1. loop
```C
for(int i=0;i<N;i++){
    if(array[i]<minVal){
        minVal=array[i];
    }
}
```
2. recursion
```C
int recursiveMin(int[] array,int index, int N){
    if(index==N-1) return array[index];
    return min(array[index],recursiveMin(array,index+1,N));
}
```
## Runtime Estimate
1. Identify the peices of straight-line code that are bried deepest in the method's loops
2. We count how many times these innermost peices of the program are executed as a function of n.

### Simple Method
```C
int findMin(int* a, int N){
    int minVal=a[0];
    for(int i=1;i<N;i++){
        if(a[i]<minVal){ //these are straight-line code.
            minVal=a[i];
        }
    }
    return minVal;
}
```
- how many times will the above execute 
```C
for (int i=1;i<n;i++){
    minVal=a[i];
}
```
  - for the first execution i=1
  - for the loop stops at i=n
  - i increases by 1 every loop execution
  - the loop then executes: [n-1]/1=**n-1** times

## Generalize
- The straigh-line code executes N-1 times.
- we can say the code runs approximately N times.
  - grows linearly with N
  