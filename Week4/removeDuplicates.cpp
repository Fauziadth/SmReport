SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    if (head == NULL) return head; //list empty

    SinglyLinkedListNode* tmp = head;
    //because the data is already in ascending order we just need to store each item until meet a difference data
    while (tmp->next != NULL && head->data == tmp->next->data) {
        tmp->next = tmp->next->next; 
    }
    head->next = removeDuplicates(head->next);

    return head;
}