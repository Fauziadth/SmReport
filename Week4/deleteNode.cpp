SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    
    SinglyLinkedListNode* cnode = head; //for pointer
    if (position == 0) return head->next;

    for (int i = 0; i<position-1; i++){
        cnode = cnode->next;
    }

    cnode->next = cnode->next->next; //skipping one node or ignoring the next node = delete the node
    
    return head;
}