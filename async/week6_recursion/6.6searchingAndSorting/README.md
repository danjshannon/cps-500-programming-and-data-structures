# 6.6 Searching and Sorting
## Finding an Element
## Brute Force
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

## Sorted Access
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

## Better way
- How else can we leverage the sorted data?
- An array has random access. Accessing any location takes the same amount of time.
- Compare against the middle element.
  - If the middle is less than the target value, then we don't nee to search in the first half on the array.
  - If the middle is greater than the target value, then we don't need to search in the second half of the array.
- Apply this logic recursively to the remaining array.

## Binary Search
```C
int binarySearch(int * array. int value, int lo, int hi){
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

## Trinary Search?


## Merge Sort
- Given an unsorted array, rearrange the elements to ascendingly sorted order.
- Algorithm
  - Divide the list into two halves
  - rescursiely call merge sort on each half.
  - base case: once a subarray has only a single element, it is sorted.
  - Merge the result from the two recursive calls into a sorted result.

```C
void mergeSort(int[] array, int left, int right){
    if(left<right){
        int middle =left+(right-left)/2;
        mergeSort(array,left,middle);
        margeSort(array.middle+1,right);
        merge(array,left,middle,right);
    }
}

void merge(int[] array, int left, int middle, int right){
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

## performance
- The dividing in haf results in log(n) levels
- merging takes O(k)
- each levels has n elements in  total - O(n)
- O(log(n))*O(n)=O(n log(n))

# Quick Sort
- Recursive sorting algo
- pick a pivot element in the array
- rearrange other elements such that lesser elements come before the pivot and all greater elements come after the pivot
- Recursively reapply the algorithm to the left and right sublists now

```C
void quickSort(int [] array, int low, int high){
    if(low<high){
        int p = partition(array,low,high);
        quickSort(array,low,p-1);
        quickSort(array,p+1,high);
    }
}
```
```C
int partition(int[] array, int low, int high){
    int pivot = array[high];
    int i= low-1;
    for(int j=low;j<high-1;j++){
        if(array[j]<=pivot){
            i++;
            swap(array, i. j);
        }
    }
    swap(array,i+i,high);
    return i+1;
}
```
## Performance
- average is O(n log(n))
- the worst case is O(n<sup>2</sup>)

## Quick Sort vs Merge Sort
- quick sort does O(n) work to split the array **before recursion**
- merge sort does O(n) work to combine the results **after recursion**