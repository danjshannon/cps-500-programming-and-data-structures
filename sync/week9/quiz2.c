#include <stdio.h>
#include <stdlib.h>

typedef struct stringNode
{
    char c;
    struct stringNode *next;
} Node;

typedef struct list
{
    Node *head;
} List;

List *stringToList(char *string, int size)
{
    List *list = malloc(sizeof(list));
    for (int i = 0; i < size; ++i)
    {
        Node *node = malloc(sizeof(Node));
        //Assign the data to the value
        node->c = string[i];
        //Assign the next element to what head points to.
        node->next = list->head; // whatever list->head points to, point node->next to the same thing
        //assign the head of the list to the node
        list->head = node;
        // addHead(list, string[i]);
    }
    return list;
}

void traverse(List *list)
{
    Node *current = list->head; //this is a POINTER to a list node, not a new ListNode
    while (current != NULL)
    {
        printf("%c->", current->c);
        current = current->next;
    }
    printf("NULL\n");
}

int f(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else if (a == b)
    {
        return f(a - 1, b - 1) + (2 * a) - 1;
    }
    else if (a > b)
    {
        return f(a - b, b) + f(b, b);
    }
    else if (a < b)
    {
        return f(a, a) + f(b - a, a);
    }
}

void LinkedListFun(Node *head)
{
    if (head == NULL)
        return;

    LinkedListFun(head->next);
    printf("%c  ", head->c);
}

int main()
{
    char *string = "hello";
    int size = 5;
    List *list = stringToList(string, size);
    traverse(list);

    LinkedListFun(list->head);
    printf("\n");

    printf("f(%d,%d)=%d\n", 0, 1, f(0, 1));
    printf("f(%d,%d)=%d\n", 2, 2, f(2, 2));
    printf("f(%d,%d)=%d\n", 2, 3, f(2, 3));
    printf("f(%d,%d)=%d\n", 3, 2, f(3, 2));
}