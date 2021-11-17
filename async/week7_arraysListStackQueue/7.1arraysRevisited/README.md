# Arrays Revisited

## Array Introduction
- Arrays are contiguous, fixed-size memory allocations of multiple variables of the same type.

```C
int array[5];
```

## Access Time
- Array access time is constant time: **O(1)**
  - Each cell in the array is the same size
  - addres of starting point of array stroe in array variable
  - array[i]: address of ith index of 
    - *array = (starting address) + i\*(size of type)*

## Adding/Removing Elements
- Arrays are fixed size!
  - No adding or deleting to existing array
  - can overwrite and shift
  - can create array larger than what we need
- if an array is full, we can create a new, larger array and copy values over
  - takes **O(n)** time to copy array

## Dynamically Sized Arrays
- Does size management behind the scenes
- Ensures that there are enough unused slots in array
- Automatically resizes when out of room (all data store on the heap)
- Uses more memory than arrays
- Access time is still constant
- We can use something called amortized analysis for insert new elements
  - if there is still room in the array, just insert it
  - if there is no more room, then double its size and copy the elements.
  - On average, many inserts will be O(1)
- Removing an element still requres shifting elements to fill the gap: O(n)