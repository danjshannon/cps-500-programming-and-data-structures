# Week 7
## Themes
- Time vs Space: We can generally trade off time for space.
- We must consider the amount of memory used versus time used.

## Arrays
1. Can arrays have elements of varying sizes? NO
2. How is array indexing: O(1)?
  - The formula to access &A[i]=@A+i*sizeof(A[0])

### Dynamically sized arrays
- implementation of arrays - not provided natively
- Resizing of arrays means creating a new array and copying of ther values
- Inserting is (average) O(1)
- Removal tends towards O(N) due to array management
- Reading is still O(1)

- Arrays are contiguous in memory

## Linked Lists
- elements (nodes) connected by pointers
- Dynamic
  - A node is added only when necessary
  - A node is deleted when done
  - size of list is not static

```C
typedef struct node{
    int numVal;
    char charVal;
    float floatVal;
    Node* next;
} Node;
```

- lists generally have elements of the same size

### Modifying Lists
- Add at head
- add at tail
- ad

## Doubly Linked Lists
- Pointers to next and previous nodes
- More bookkeeping
- easier to traverse
- if you know your list is in order, you can traverse smarter
  - node in second half, start at end


## Stacks and Queues
### Implementations
- O(1) for pop push
### Queues
- First in First out
  - FIFO
### Stacks
- Last in First out
  - LIFO

## Homework 7
```C
typedef struct list{
    Node* head;
    int count;// doesn't affect the runtime/funcitonality of the list
}
```

- build out stacks using array and list, then build queue
  - the code will be *very* similar
- No office hours this week.
- Quiz 2 two weeks after thanksgiving