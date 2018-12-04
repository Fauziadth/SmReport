SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == NULL && head2 == NULL) return head1;//or head2, they're the same
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    //if both have data
    //comparing to sorting while merging
    if(head1->data <= head2->data){
        head1->next = mergeLists(head1->next, head2);
    }
    else if(head1->data > head2->data){
        //we need to store the root of head2 and moving the pointer of head2 to its child.
        SinglyLinkedListNode* temp = head2;
        head2 = head2->next;
        temp->next = head1;
        //put the root of head2 to head1
        head1 = temp;
        head1->next = mergeLists(head1->next, head2);
    }

    return head1;
}