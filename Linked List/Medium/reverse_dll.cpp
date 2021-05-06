// we just have to swap the next and prev pointers of each node

Node* reverseDLL(Node * head)
{
    if(!head || !head->next)
    return head;
    
    Node* curr = head, *temp = NULL;
    
    while(curr)
    {
        // three steps for swapping
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        // updating prev for next iteration => curr->prev was before curr->next
        curr = curr->prev;
    }
    
    head = temp->prev;       // temp will be at the last second node (as prev was next before swapping)
    
    return head;
}