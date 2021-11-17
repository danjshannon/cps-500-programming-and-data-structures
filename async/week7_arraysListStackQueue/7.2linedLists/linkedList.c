#include <stdio.h>

typedef struct listNode
{
    int data;
    struct listNode *next;
} ListNode;

typedef struct list
{
    ListNode *head;
    ListNode *tail; //optional!
} List;

typedef struct doublyListNode
{
    int data;
    struct doublyListNode *next;
    struct doublyListNode *prev;
} DoublyListNode;

void addHead(List *list, int value)
{
    //Create a new node to hold value.
    ListNode *node = malloc(sizeof(ListNode));
    //Assign the data to the value
    node->data = value;
    //Assign the next element to what head points to.
    node->next = list->head; // whatever list->head points to, point node->next to the same thing
    //assign the head of the list to the node
    list->head = node;
}

void print(List *list)
{
    ListNode *current = list->head; //this is a POINTER to a list node, not a new ListNode
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{

    return 0;
}