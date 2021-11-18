# 7.4 List vs Array
## Inerstion at the end

## Amortized
- **Amortized** means averaged over different types of scenarios.

## Insertion at the Head
- A linked list is still constant time O(1)
- A fixed-size array has no concept of increasing size
- A dynamic array does not keep empty cells in the head of the array. We may not need to resize but still have to shift over all other elements in array. O(N)

## Insertion/Deletion in the Middle
- For a linked list, the trouble is that we first have to find the location to insert or delete in the list O(N)
- For fixed-size array, there is no concept of inserting
- For a dynamic array, we might need to resize, but at least we need to shift over all elements to the right of the insertion point. O(N)

## Indexing
- linked list: we need to interate over the pointers to find the ith position O(N)
- fixed-size array: O(1)
- dynamic array: O(1)

## Memory Overhead
- linked list: memory overhead is the next pointers, N
- fixed-size array: no overhead
- dynamic arrays: we always allocate more memory than we need to prevent having to resize

## Summary
- Lists are better for dynamic/random access data than fixed-size arrays
- Lists have slower random access, **but** if all elements are updated at the same time, there is no real penalty
- List are better at adding to the front of the collectoin, but dynamic arrays are useful because contiguous memory has some advantages outside of theory