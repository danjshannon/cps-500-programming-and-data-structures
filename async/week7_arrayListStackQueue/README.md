# Week 7: Array, List, Queue, and Stack
- [7.1 Arrays Revisited](#71-arrays-revisited)
- [7.2 Linked Lists](#72-linked-lists)
- [7.3 Reversing a Linked List](#73-reversing-a-linked-list)
- [7.4 List vs Array](#74-list-vs-array)
- [7.5 Queues](#75-queues)
- [7.6 Stacks](#76-stacks)

## 7.1 Arrays Revisited
[top](#Week-7-Array-List-Queue-and-Stack)

### Array Introduction
- Arrays are contiguous, fixed-size memory allocations of multiple variables of the same type.

```C
int array[5];
```

### Access Time
- Array access time is constant time: **O(1)**
  - Each cell in the array is the same size
  - addres of starting point of array stroe in array variable
  - array[i]: address of ith index of 
    - *array = (starting address) + i\*(size of type)*

### Adding/Removing Elements
- Arrays are fixed size!
  - No adding or deleting to existing array
  - can overwrite and shift
  - can create array larger than what we need
- if an array is full, we can create a new, larger array and copy values over
  - takes **O(n)** time to copy array

### Dynamically Sized Arrays
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

## 7.2 Linked Lists
[top](#Week-7-Array-List-Queue-and-Stack)
### Arrays are fast but...
- arrays have constant access time
- adding/removing to an array is difficult

### Singly Linked List
- a node is an element in the list
- nodes have two components:
  1. Data (int, double, objects etc)
  2. Pointer to the next Node in the list

```C
typedef struct listNode
{
    int data;
    struct listNode *next;
} ListNode;
```
- a list just needs to keep track of the head of the list (but can do more such as the tail)
```C
typedef struct list
{
    ListNode *head;
    ListNode *tail; // tail is optional
} List;
```
- tail pointer has NULL data

### Traversing Lists
```C
void print(List *list)
{
    ListNode *current = list->head;//this is a POINTER to a list node, not a new ListNode
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
```

### List traversal Runtime
- if the size of the list is N, we will traverse N times
- O(N)

### Random vs Sequential Access
- **Random Access** to a data structure implies that each access is completely independent
  - arrays provvide better random access time: O(1)
  - Lists provide O(N) access time
- **Sequential Access** to a data structure implies that the data will be accessed in the order in which it is stored in.
  - To access all elements in an array in  order will be O(N)
  - To access all elements of a list in order will be O(N)

### Modifying Lists
### Adding at the Head
```C
void addHead(List *list, int value)
{
    //Create a new node to hold value.
    ListNode *node = malloc(sizeof(ListNode));
    //Assign the data to the value
    node->data = value;
    //Assign the next element to the head.
    node->next = list->head;// whatever list->head points to, point node->next to the same thing
    //assign the head of the list to the node
    list->head = node;
}
```
- in C and C++ you need to manually deallocate memory for the nodes of linked lists
- node is a pointer on the *stack*
  - memory it points to is on the *heap*

### Adding at the head runtime
- Constant time O(1)!
- adding to the tail is O(1) as well
- What about adding in the middle element?

### Inserting in the middle
- We first have to iterate to spot where we want to insert the new node
  - O(N)
- Once we find the element to insert after, it's constant time

### Removing from the middle
- Same idea fo removing a node
- performance: O(N) since we need to first find the node
  - removing is O(1)
- deleting the tail of the list
  - O(N) for a singly linked list

### Doubly Linked Lists
- if data re needed to be used in both standard and reverse order sequentially, then we can use a **doubly linked list**
```C
typedef struct doublyListNode
{
    int data;
    struct doublyListNode *next;
    struct doublyListNode *prev;
} DoublyListNode;
```
- the last node in a doubly list has a *next* pointer pointing to null.

### Doubly vs Singly Linked List
- (-) a DLL uses more space (one extra pointer per node).
- (-) a DLL is slightly more complex to implement.
- (+) a DLL can iterate in both directions.
- (+) if we have a pointer to a node already, then removing it is simple in a DLL.
  - In an SLL, we first need to find the previous node to chang that node's next pointer.

## 7.3 Reversing a Linked List
[top](#Week-7-Array-List-Queue-and-Stack)
- Something every programmer should know how to do.
- Very common interview question.
- can be down via recursion or iteration.

### Iterative Reverse List
- *for a singly linked list*
```C
void reverse(List* list){
    if(list->head==NULL){
        ListNode* prev=NULL;
        ListNode* ptr=head;
        while(ptr!=NULL){
            ListNode* ptr=head;
            ptr->next=prev; // This line changes list
            prev=ptr; // this line only changs where some pointer points to (not part of list)
            ptr=tmp;
        }
        list->head=prev; // this line chages list
    }
}
```
- O(N)

## 7.4 List vs Array
[top](#Week-7-Array-List-Queue-and-Stack)
### Inerstion at the end

### Amortized
- **Amortized** means averaged over different types of scenarios.

### Insertion at the Head
- A linked list is still constant time O(1)
- A fixed-size array has no concept of increasing size
- A dynamic array does not keep empty cells in the head of the array. We may not need to resize but still have to shift over all other elements in array. O(N)

### Insertion/Deletion in the Middle
- For a linked list, the trouble is that we first have to find the location to insert or delete in the list O(N)
- For fixed-size array, there is no concept of inserting
- For a dynamic array, we might need to resize, but at least we need to shift over all elements to the right of the insertion point. O(N)

### Indexing
- linked list: we need to interate over the pointers to find the ith position O(N)
- fixed-size array: O(1)
- dynamic array: O(1)

### Memory Overhead
- linked list: memory overhead is the next pointers, N
- fixed-size array: no overhead
- dynamic arrays: we always allocate more memory than we need to prevent having to resize

### Summary
- Lists are better for dynamic/random access data than fixed-size arrays
- Lists have slower random access, **but** if all elements are updated at the same time, there is no real penalty
- List are better at adding to the front of the collectoin, but dynamic arrays are useful because contiguous memory has some advantages outside of theory

## 7.5 Queues
[top](#Week-7-Array-List-Queue-and-Stack)
- Queues are an **abstract data type**
  - A mathematical model for how we interact with data
- A **queue** is a collection of ordered data that has two main methods
  - **enqueue**: add a new item to the collection
  - **dequeue**: remove the oldest item from the collection
  - both enqueue and dequeue are O(1)

### FIFO
- Queues are FIFO (first in first out)
- When dequeue is called, the item that was added first is removed
- *first come first serve*

### Queue Implementations
- ADTs are implementation agnostic
- We can implement a queue any way we want provided behaviour matched previous ADT behavior
- Common implmenetations
  1. List: just use head and tail pointer for enqueue and dequeue, respectively
  2. Array: keep track of index to enqueue into and index to dequeue from

## 7.6 Stacks
[top](#Week-7-Array-List-Queue-and-Stack)
### Stacks
- **Stacks** are another abstract data type (ADT)
- **similar to stack memory*
- There are two main methods:
  - Push: add another element onto the top of the collection
  - Pop: remove the top element from the collection
  - both operations are O(1)
### LIFO
- stacks are LIFO (last in first out)
- an ordered collection of data where the last element added is the first element out
- we can implement a stack any way we want
- common implementations:
  - List: keep track of just the head; pop and push both affect just the head
  - Array: keep track of the top of the stack; push and pop from the same index
