# 7.5 Queues
- Queues are an **abstract data type**
  - A mathematical model for how we interact with data
- A **queue** is a collection of ordered data that has two main methods
  - **enqueue**: add a new item to the collection
  - **dequeue**: remove the oldest item from the collection
  - both enqueue and dequeue are O(1)

## FIFO
- Queues are FIFO (first in first out)
- When dequeue is called, the item that was added first is removed
- *first come first serve*

## Queue Implementations
- ADTs are implementation agnostic
- We can implement a queue any way we want provided behaviour matched previous ADT behavior
- Common implmenetations
  1. List: just use head and tail pointer for enqueue and dequeue, respectively
  2. Array: keep track of index to enqueue into and index to dequeue from