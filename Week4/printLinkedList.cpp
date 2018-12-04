void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* cnode = head; //for pointer

    while (cnode != NULL){
        cout<<cnode->data<<"\n";
        cnode = cnode->next;
    }

}