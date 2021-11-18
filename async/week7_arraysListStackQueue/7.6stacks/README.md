# 7.6 Stacks
## Stacks
- **Stacks** are another abstract data type (ADT)
- **similar to stack memory*
- There are two main methods:
  - Push: add another element onto the top of the collection
  - Pop: remove the top element from the collection
  - both operations are O(1)
## LIFO
- stacks are LIFO (last in first out)
- an ordered collection of data where the last element added is the first element out
- we can implement a stack any way we want
- common implementations:
  - List: keep track of just the head; pop and push both affect just the head
  - Array: keep track of the top of the stack; push and pop from the same index