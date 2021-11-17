# Linked Lists
## Arrays are fast but...
- arrays have constant access time
- adding/removing to an array is difficult

## Singly Linked List
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

## Traversing Lists
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

## List traversal Runtime
- if the size of the list is N, we will traverse N times
- O(N)

## Random vs Sequential Access
- **Random Access** to a data structure implies that each access is completely independent
  - arrays provvide better random access time: O(1)
  - Lists provide O(N) access time
- **Sequential Access** to a data structure implies that the data will be accessed in the order in which it is stored in.
  - To access all elements in an array in  order will be O(N)
  - To access all elements of a list in order will be O(N)

## Modifying Lists
## Adding at the Head
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

## Adding at the head runtime
- Constant time O(1)!
- adding to the tail is O(1) as well
- What about adding in the middle element?

## Inserting in the middle
- We first have to iterate to spot where we want to insert the new node
  - O(N)
- Once we find the element to insert after, it's constant time

## Removing from the middle
- Same idea fo removing a node
- performance: O(N) since we need to first find the node
  - removing is O(1)
- deleting the tail of the list
  - O(N) for a singly linked list

## Doubly Linked Lists
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

## Doubly vs Singly Linked List
- (-) a DLL uses more space (one extra pointer per node).
- (-) a DLL is slightly more complex to implement.
- (+) a DLL can iterate in both directions.
- (+) if we have a pointer to a node already, then removing it is simple in a DLL.
  - In an SLL, we first need to find the previous node to chang that node's next pointer.