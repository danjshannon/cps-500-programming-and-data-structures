# 5.5 Sorting Examples
## Selection Sort
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

## Insertion Sort
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

## Terminology
- Best-case runtime
- Worst-case rutime
- Average-case runtime

## Case vs Bound
- foreach case (best,worst,average), we can find the big-O, big-omega, and theta
- These are orthoginal concepts
- However, we typically care about:
  1. The big-o (upper bound) of the worst case as this gives us the the true upper bound of the alogorithm
  2. The big-&omega; (lower bound) of the best case, as this gives us the true lower bound of the algorithm

## Bubble Sort
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