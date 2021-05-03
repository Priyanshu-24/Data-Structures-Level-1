// the first method is to run two loops and check

// second and efficient solution is to use a set and store data
// and take a prev node to keep check of previous nodewhich will help us in deletion

Node * removeDuplicates( Node *head) 
{
    if(!head && !head->next)
    return head;
    
    Node *curr=head,*prev=NULL;
    
    unordered_set<int>pp;
    
    while(curr)
    {
        if(pp.find(curr->data)!=pp.end())
        {
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
        }
        
        else{
            pp.insert(curr->data);
            prev=curr;
            curr=curr->next;
        }
    }
    
    return head;
}
