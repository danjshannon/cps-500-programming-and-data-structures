# 7.3 Revesing a Linked List
- Something every programmer should know how to do.
- Very common interview question.
- can be down via recursion or iteration.

## Iterative Reverse List
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