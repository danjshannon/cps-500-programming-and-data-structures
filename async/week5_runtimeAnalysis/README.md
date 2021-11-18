# Week 5: Runtime Analysis
- [Home](/README.md#cps-500-programming-and-data-structures)
- [5.1 Runtime Analysis](#51-Runtime-Analysis)
- [5.2 Proportional Rates of Growth](#52-Proportional-Rates-of-Growth)
- [5.3 Limit Rule](#53-Limit-Rule)
- [5.4 Loop Analysis](#54-Loop-Analysis)
- [5.5 Sorting Examples](#55-Sorting-Examples)
## 5.1 Runtime Analysis 
[top](#Week-5-Runtime-Analysis)

### How to measure algorithm speed
- **option 1** implement the algorithm and instrument to measure how long it takes.
  - would do this for multiple input sizes.
  - There are a lot of possible inputs/
  - Time differs based on a lot of variables - ram, cpu, other programs running
### Measure algorithm growth
- **option 2** Mathematically measure the runtime of an algorithm as a function of the size of the input.
  - n: n&isin;N
  - Finding precise funtion is hard, estimate usually good enough.
### Striaght-line code
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
### Runtime Estimate
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

### Generalize
- The straigh-line code executes N-1 times.
- we can say the code runs approximately N times.
  - grows linearly with N
  
## 5.2 Proportional Rates of Growth
[top](#Week-5-Runtime-Analysis)
### Big-O

O(g(n))={f(n):there exists (&exist;) positive constances c and n<sub>0</sub> such that 0&le;f(n)&le;c*g(n),for all n&ge;n<sub>0</sub>}

- n is the size of the input to the problem
- f(n) is a function that characterizes the *actual* running time of the alogrithm
- g(n) is a function that characterizes an upper bounds on f(N). It is a limit on the running time of the algorithm
- n<sub>0</sub>, c are arbitrary constants that make the above formula true

**f(n) &isin; O(g(n))**
- we want to create an upper bound on f(n)
- g(n) is an **asymptotic upper bound** for f(n)
- if f(n) &isin; O(g(n)), we write f(n)=O(g(n))

### Example:
- 2n<sup>2</sup>=O(n<sup>3</sup>) with M=1 and x<sub>0</sub>=2
- functions in O(n<sup>2</sup>)
  - n<sup>2</sup>
  - n<sup>2</sup> + n
  - n<sup>2</sup> + 1000n
  - 1000n<sup>2</sup> + 1000n

### Big-O notation in practice
- Pay attention to dominant terms
- Don't include constants in O
- We generally only care about the smallest g such that f(x) is int (O(g(x)))

### Big-O rules
1. If f(n) is a polynomial of degree d, then f(n) is O(n<sup>d</sup>)
2. Use the smallest possible class of functions if possible
3. Use the simplest expression of the class

## Bit-Omega (Lower Bound)
&omega;(g(n))={f(n): &exist; positive constances c and n<sub>0</sub> such that 0&le;c*g(n)&le;f(n), for all n&ge;n<sub>0</sub>}
- looking for a lower bound.
- g(n) is a function that characterizes a lower bound on f(n). It is a limit on how fast the running time of the algo can be.

**f(n) &isin; &omega;(g(n))**
### example

f(n)=100n<sup>2</sup>+8000n+97

- Claim f is in &omega;(n)
- n&le;100n<sup>2</sup>+8000n+97, for n>0
- c=1, n<sub>0</sub>=0

### example

&radic;n = &omega;(lg(n))

- c=1, n<sub>0</sub>=16

## Big Theta

&theta;(g(n))={f(n): &exist; positive constants c<sub>1</sub> and c<sub>2</sub> such that 0&le;c<sub>1</sub>*g(n)&le;f(n)&le;c<sub>2</sub>*g(n) for all n&ge;n<sub>0</sub>}

- g(n) is a function that characterizes a tight bounds on f(n). 
- It is a limit on how fast and how slow the running time of the algo can be.

**f(n) &isin; &theta;(g(n))**

- g(n) is **asymptotically tight bound** for f(n)
- **Theorem**: &theta;(g(n))=O(g(n))&cap;&omega;(g(n))
- f(n)=&theta;(n)&rarr;f(n)=O(g(n)) and f(n)=&omega;(g(n))

### &theta; Notation Example
- n<sup>2</sup>/2-n=&theta;(n<sup>2</sup>) with c1=1/4, c2=1/2, n0=8

### Asymptotic Analysis
- **Asymptotic Analysis** is a way to describe behavior of functions in the limit
- Describes the growth of functions
- abstract away lower order terms and constant functions
  - focus on what's important
- How we indicate running times of algorithms

O&asymp;&le;

&omega;&asymp;&ge;

&theta;&asymp;=

## 5.3 Limit Rule
[top](#Week-5-Runtime-Analysis)\
lim(n->&infin;)f(n)/g(n)=c
- Where 0&le;c&le;+&infin;

- if 0 < c < +&infin; then f(n) &isin; &theta;(g(n)), O(g(n)), and &omega;(g(n))
- if c = 0 then f(n) &isin; O(g(n)), but f(n) &notin; &theta;(g(n)),&omega;(g(n))
- if c = &infin; then f(n) &isin; &omega;(g(n)), but f(n) &notin; &theta;(g(n)),O(g(n))

### Limit Rule Example
- FindMin: f(n)=n-1
- claim: f(n)=&theta;(n)
- lim(n&rarr;&infin;)f(n)/g(n)
- lim(n&rarr;&infin;)(n-1)/n
- lim(n&rarr;&infin;)[(n/n)-(1/n)]
- lim(n&rarr;&infin;)[1-(1/n)]
- lim(n&rarr;&infin;)[1-(1/&infin;)]
- lim(n&rarr;&infin;)[1-0]=1
- if 0<1<+&infin;, then f(n)=&theta;(n)

### Potential limit rule example
- f(n)=n<sup>3</sup>-n<sup>2</sup>-1
- claim: f(n)=&omega;(n)
- lim(n&rarr;&infin;)f(n)/g(n)
- lim(n&rarr;&infin;)(n<sup>3</sup>-n<sup>2</sup>-1)/n
- lim(n&rarr;&infin;)n<sup>2</sup>-n-(1/n)
- lim(n&rarr;&infin;)&infin;<sup>2</sup>-&infin;-(1/&infin;)
- lim(n&rarr;&infin;)&infin;-&infin;-0
- lim(n&rarr;&infin;)n<sup>2</sup>=&infin;
- Therefore f(n)=&omega;(n)

### Big-) limit rule example
- f(n)=n
- claim: f(n)=&omega;(n)
- lim(n&rarr;&infin;)f(n)/g(n)
- lim(n&rarr;&infin;)n/n<sup>2</sup>
- lim(n&rarr;&infin;)1/n
- lim(n&rarr;&infin;)1/&infin;=0;
- therefore f(n)&isin;O(n<sup>2</sup>)

## 5.4 Loop Analysis
[top](#Week-5-Runtime-Analysis)

- State of the O of each of the following loops in terms of N
1. 
```C
for (int i =1; i<N; i*=2){...}
```
  - i=1
  - i=2
  - i=4
  - i=8
  - general form: i=2<sup>k</sup>, where k is the number of iterations
  - stop when i&ge;N
  - 2<sup>k</sup>&ge;N
  - 2<sup>k</sup>=N
  - log<sub>2</sub>(2<sup>k</sup>)=log<sub>2</sub>(N)
  - k=log<sub>2</sub>(N)
  - k is the number of iterations, so the loop with run *log<sub>2</sub>(N)* times.
  - O(log(N))

2. 
```C
for (int i =0;i<N*N;i+=3){
    for( int j=N; j>0; j-=4){...}
}
```
  - when the step function is + or -
  - |start-end|/|step size|
  - outer loop
    - for (int i =0;i<N*N;i+=3)
    - |N<sup>2</sup>-0|/|3| = N<sup>2</sup>/3=O(N<sup>2</sup>)
  - inner loop
    - for( int j=N; j>0; j-=4)
    - |N-0|/|4| = N/4 = O(N)
  - since the two loops have no dependencies on variables we can multiply:
  - O(N<sup>2</sup>) * O(N) = O(N<sup>3</sup>)
3. 
```C
for (int i =1;i<N;i*=3){
    for( int j=0; j<i; j++){...}
}
```
  - Outer loop
    - (int i =1;i<N;i*=3)
    - Similar to loop ##1, we get O(log(N))
  - Inner Loop
    - for( int j=0; j<i; j++)
    - |i=0|/1=O(i)...?
      - we want O(n) not O(i)
    - ![Runtime Table](https://github.com/danjshannon/cps-500-programming-and-data-structures/blob/main/async/week5_runtimeAnalysis/loopAnalysisTable.png)
    - sum &sum; the last column - geomoetry summation
  - O(N)

## 5.5 Sorting Examples
[top](#Week-5-Runtime-Analysis)
### Selection Sort
- Selection sort works by:
  1. Finding the smallest number and putting it in the 0th index
  2. Then finding the second smallest number and putting it in the first index
  3. And so on until the array is sorted

```C
void selectionSort(int *a, int N)
{
    int minJ, minVal;
    for (int i = 0; i < N - 1; i++)
    {
        //find a minJ &isin; {1,...,n-} such that:
        // a[minJ]=min{a[j]:i<=j<=n-1}
        minJ = i;
        minVal = a[i];
        for (int j = i + 1; j <= N - 1; j++)
        {
            if (a[j] < minVal)
            {
                minJ = j;
                minVal = a[j];
            }
        }
        //swap the values of a[i] and a[minJ]
        a[minJ] = a[i];
        a[i] = minVal;
    }
}
```
### Identify Innermost Code
1. identify the peices of straight-line code that are buried deepest.
2. For selection sort, the innermost code is:
```C
if (a[j] < minVal)
{
    minJ = j;
    minVal = a[j];
}
```
### Count Execution
2. Count how many times these innermost pieces of the program are executed for a given value of n.\
- inner loop: executes [n-(i+1)]/1 = **n-i-1 times**
- outer loop: executes [(n-1)-0]/1 = **n-1 times**
- innermost code: **O(n<sup>2</sup>)**

### Insertion Sort
- Insertion sort works byL
  1. Selects on item (ith index) at a time (starting at 1)
  2. Everything to the left of i is already sorted
  3. Inserts it into the growing sorted section to the left of i
  4. repeat for i=[1,...,N-1]
```C
void insertionSort(int *a, int N)
{
    for (int i = 1; i < N; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
```
### Identify Innermost Code
```C
a[j + 1] = a[j];
j = j - 1;
```
### Already sorted input:
- Case 1: suppose that the input array is already sorted.
- a[i-1]>a[i] will never be true
- Run N-1 times
- insertionSort &isin; O(n)

### Decreasingly Sorted Input:
- case 2: suppose the input array is decreasingly sorted.
- a[i-1]>a[i] will always be true
- insertionSort &isin; O(n<sup>2</sup>)

### Terminology
- Best-case runtime
- Worst-case rutime
- Average-case runtime

### Case vs Bound
- foreach case (best,worst,average), we can find the big-O, big-omega, and theta
- These are orthoginal concepts
- However, we typically care about:
  1. The big-o (upper bound) of the worst case as this gives us the the true upper bound of the alogorithm
  2. The big-&omega; (lower bound) of the best case, as this gives us the true lower bound of the algorithm

### Bubble Sort
- repeatedly iterates through the list
  - compares pairs of adjacent elements
  - if the two elements are out of order, swap them
  - continue until no more swaps are needed
- bubble because large items tend to bubble to the top of the list
```C
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp1 = arr[j];
                int temp2 = arr[j + 1];
                arr[j] = temp2;
                arr[j + 1] = temp1;
                swapped = 1;
            }
        }
        if (swapped==0)
            break;
    }
}
```

### Performance
- outer loop: n-1 times
- inner loop: n-i-1 times
- O(n<sup>2</sup>) runtime
- O(n) if already sorted
- Bubble sort is the worst!