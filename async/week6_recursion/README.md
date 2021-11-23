# Week 6: Recursion
- [Home](/README.md#cps-500-programming-and-data-structures)
- [6.1 Recursion](##61-recursion)
- [6.2 Factorial Example](##62-Factorial-Example)
- [6.3 GCD Example](##63-GCD-Example)
- [6.4 Fibonacci Numbers](##64-Fibonacci-Numbers)
- [6.5 Tail Recursion](##65-Tail-Recursion)
- [6.6 Searching and Sorting](##66-Searching-and-Sorting)

## 6.1 Recursion
[top](#Week-6-Recursion)
- Involves a function calling itself.

### Introduction to Recursion
- A recursive method is a method that calls itself.

### Simple Example
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

### A recursive method
1. **Base Case** We are unable to subdivide the problem any thurther and need to compute the result of the problem at hand.
  - make it stop
2. **Recursive Case** We can further subdivide the problem and may have logic that details how to combine the result from the smaller problems.
  - continue recursing

### Why Recursion?
- some algorithms are simpler to write and read using recursive functions
- compared with iteration
  - Generally slower than loops
  - Everything that can be done with recursion can be done with iteration and vice versa

### Steps to Solve
1. The base-case question.
  - **Is there a nonrecursive way out of the cuntion and does the routine work correctly for this "base" case?**
2. The smaller-caller question
  - **Does each recursive call to the function involve a smaller case of the original problem, leading inescapably to the base case?**
3. The general-case question:
  - **Assuming that the recursive call(s) work(s) correctly, does the whole funciton work correctly?**

### Infinite Recursion
- Mistakes in the base case can lead to infinite recursion
- This is similar to infinite loop, but in this case it will eventually crash the program
  - Due to stack memory segment overflow

## 6.2 Factorial Example
[top](#Week-6-Recursion)
n! = n* (n-1)*(n-2)*...*1

```C
// Iterative
int factorial(int n){
    int result =1;
    for( int i = 2; i<=n;i++){
        result *= i;
    }
    return result;
}
```
```C
// Recursive
int factorial(int n){
    if (n==0) {
        return 1;
    }
    return n * factorial(n-1);
}
```

### Recursive Runtime
- For now:
  - number of recursive calls **times** work to break problem up **times** work to combine results
- Factorial example is O(n) runtime

## 6.3 GCD Example
[top](#Week-6-Recursion)
### Greatest Common Divisor
- The greatest common divisor of two or more integers (which are not both zero) is the largest positive integer that divides each of the integers.
```C
int gcd(int x, int y) {
    if (y==0) {
        return x;
    }
    return gcd(y, x%y);
}
```
### GCD Number of Recursive Calls
- Assume: A>B
- Claim:  A%B<.5A
- if B=.5A then A%B=0
- if B<.5A then X%B<B<.5A
- if B>.5A then A%B<=A-B<.5A
- Proof of running time
  - GCD(A,B) calls GCD (B,<.5A)
  - Which calls GCD(<.5A,B%<.5A)

## 6.4 Fibonacci Numbers
[top](#Week-6-Recursion)
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
### Fibonacci Runtime
- We can take an upper and lower bound
- The depth of the tree will be n-1 since on the left-most branch we subtract 1 at every step..
- The right-most branch of the tree will be the shortest since it subtracts by 2. Each step will have n/2-1 levels
- Each full level will have 2<sup>k</sup> nodes where k is the level.
- Recursive runtime is between
  - **&radic;(2)<sup>n</sup>**
  - **2<sup>n</sup>**
- Precise runtime is &phi;<sup>n</sup>
  - &phi;~=1.618 (golden ratio)

### Iterative Fibonacci
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

## 6.5 Tail Recursion
[top](#Week-6-Recursion)
### Recursion vs Iteration
- Generally, a recursive algorithm produces a slower than equivalent iterative algorithm
- This is due to the overhead of function calls pushing arguments and control values onto the stack
- we may also run out of room on the stack memory segment as each function uses a portion of the stack
  - This results in a stack overflow
  - Recursive solutions don't typically scale well.

### Tail Recursion
- One where every recursive call is the last thing done by the function before returning and thus produces the function's value
- the benefit of tail recursion is that there are compiler techniques that can replace tail recursion with iteration at the assembly level.
**GCD is a tail recursive algorithm**

### Transofrm to Tail Recursion
- Can we transform any of the existing algos to tail recursion


### Tail Factorial
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

## 6.6 Searching and Sorting
[top](#Week-6-Recursion)
### Finding an Element
### Brute Force
- Lets say we have an array of integers. How do we check if a given value is present?

```C
int search(int* array, int size, in value){
    for (int i=0;i<size;i++){
        if(array[i]==value){
            return i;
        }
    }
    return -1;
}
```
- O(n) runtime

### Sorted Access
- What if we know the array is sorted
```C
int search(int* array, int size, in value){
    for (int i=0;i<size;i++){
        if(array[i]==value){
            return i;
        }else if(array[i]>value){
            return -1;
        }
    }
    return -1;
}
```
- Still O(n) runtime

### Better way
- How else can we leverage the sorted data?
- An array has random access. Accessing any location takes the same amount of time.
- Compare against the middle element.
  - If the middle is less than the target value, then we don't nee to search in the first half on the array.
  - If the middle is greater than the target value, then we don't need to search in the second half of the array.
- Apply this logic recursively to the remaining array.

### Binary Search
```C
int binarySearch(int * array, int value, int lo, int hi){
    if(lo>hi){
        return -1;
    }
    int middle=(hi-lo)/2;
    if (array[middle]==value){
        return middle;
    }else if (array[middle]<value){
        return binarySearch(array,value,middle+1,hi);
    }else{
        return binarySearch(array,value,lo,middle-1);
    }
}
```
- Work to break problem up - O(n)
- Work to combine results - tail recursive O(n)
- Number of recursive calls? O(log(n))
  - N/2<sup>k</sup>...2<sup>k</sup>=N...k=log<sub>2</sub>N

### Trinary Search?


### Merge Sort
- Given an unsorted array, rearrange the elements to ascendingly sorted order.
- Algorithm
  - Divide the list into two halves
  - rescursiely call merge sort on each half.
  - base case: once a subarray has only a single element, it is sorted.
  - Merge the result from the two recursive calls into a sorted result.

```C
void mergeSort(int array[], int left, int right){
    if(left<right){
        int middle =left+(right-left)/2;
        mergeSort(array,left,middle);
        margeSort(array.middle+1,right);
        merge(array,left,middle,right);
    }
}

void merge(int array[], int left, int middle, int right){
    int temp[right-left];
    int i=left;
    int j=middle;
    int index= 0;
    while( i<middle && j<right ){
        if(array[i]<array[j]){
            temp[index]=array[i];
            i++
        }else{
            temp[index]=array[j];
            j++
        }
        index++;
    }
    while(i<middle){
        temp[index]=array[i];
        i++;
        index++;
    }
    while(j<right){
        temp[index]=array[j];
        j++;
        index++;
    }
    for(int k=0;k<right-left;k++){
        array[left+k]=temp[k];
    }
}
```

### performance
- The dividing in haf results in log(n) levels
- merging takes O(k)
- each levels has n elements in  total - O(n)
- O(log(n))*O(n)=O(n log(n))

## Quick Sort
- Recursive sorting algo
- pick a pivot element in the array
- rearrange other elements such that lesser elements come before the pivot and all greater elements come after the pivot
- Recursively reapply the algorithm to the left and right sublists now

```C
void quickSort(int array[], int low, int high){
    if(low<high){
        int p = partition(array,low,high);
        quickSort(array,low,p-1);
        quickSort(array,p+1,high);
    }
}
```
```C
int partition(int array[], int low, int high){
    int pivot = array[high];
    int i= low-1;
    for(int j=low;j<high;j++){
        if(array[j]<=pivot){
            i++;
            swap(array, i, j);
        }
    }
    swap(array,i+i,high);
    return i+1;
}
```
### Performance
- average is O(n log(n))
- the worst case is O(n<sup>2</sup>)

### Quick Sort vs Merge Sort
- quick sort does O(n) work to split the array **before recursion**
- merge sort does O(n) work to combine the results **after recursion**