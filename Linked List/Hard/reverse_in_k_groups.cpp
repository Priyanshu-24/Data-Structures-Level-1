// in this we have to reverse linked list in size of k nodes 

// solution is to reverse the list in k groups and call the reverse function for next k nodes

struct node *reverse (struct node *head, int k)
{ 
    node *curr=head,*next=NULL,*prev=NULL;
    int count=0;
    
    while(curr && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    
    if(next)
    {
        head->next=reverse(next,k);     // next will be the next node from which we will start reversing
    }
    
    return prev;
}


// in leetcode we do not have to reverse the last nodes if they are less than k 
// here the question becomes interesting and hard