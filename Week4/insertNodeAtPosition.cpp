SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    

    SinglyLinkedListNode* cnode = head; //for pointer
    for (int i = 0; i<position-1; i++){
        cnode = cnode->next;
    }

    //for making a new node to be inserted
    SinglyLinkedListNode* tmp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    tmp->data = data;
    tmp->next = cnode->next;

    cnode->next = tmp;

    return head;

}