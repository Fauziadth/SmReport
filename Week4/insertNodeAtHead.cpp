SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* tmp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    tmp->data = data;
    tmp->next = NULL;

    if(llist == NULL){
        llist = tmp;
    }else{
        tmp->next = llist;
        llist = tmp;
    }

    return llist;

}