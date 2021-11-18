void reverse(List *list)
{
    if (list->head == NULL)
    {
        ListNode *prev = NULL;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            ListNode *ptr = head;
            ptr->next = prev; // This line changes list
            prev = ptr;       // this line only changs where some pointer points to (not part of list)
            ptr = tmp;
        }
        list->head = prev; // this line chages list
    }
}