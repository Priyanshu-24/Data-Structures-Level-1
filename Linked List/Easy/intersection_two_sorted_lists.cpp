// just traversing the two lists

// Time : O(n+m) and Space : O(n+m) 

Node* findIntersection(Node* head1, Node* head2)
{
    Node* head = NULL;    // head of our new list
    Node* curr;   // current pointer to traverse the created list
    Node *temp;    // to create new node
    
    while(head1 && head2)
    {
        if(head1->data == head2->data)
        {
            if(!head)      // if it is the first node
            {
                temp = new Node(head1->data);
                head = temp;
                curr = temp;
            }
            
            else
            {
                temp = new Node(head1->data);
                curr->next = temp;
                curr = temp;
            }
            
            // donot forget to increment both the pointers in this step
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // increment the pointer with smaller data
        else if(head1->data > head2->data)
        head2 = head2->next;
        
        else
        head1 = head1->data;
    }
    
    return head;
    
}