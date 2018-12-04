SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* tmp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    tmp->data = data;
    tmp->next = NULL;

    if(head == NULL){
        head = tmp;
        return head;
    }

    SinglyLinkedListNode* cnode = head; //for pointer
    while(cnode->next != NULL){
        cnode = cnode->next;
    }
    cnode->next = tmp;

    return head;

}