// first approach is to use hashing 
// store the node in the set and check if they occur second time or not

bool cycle(Node* head)
{
    unordered_set<Node*> s;

    while(head)
    {
        if(s.find(head) != s.end())    // loop present
            return true;

        s.insert(head);   // insert node in the set i.e node appearing first time

        head = head->next;    // update head for next iteration
    }

    return false;       // came out of the loop means no cycle is present in the linked list
}

// Time O(n) and Space O(n)


// optimized method with Time O(n) and Space O(1)
// take two pointers fast and slow and run them accordingly
// moving slow by one step and fast by two steps ensures that they will meet at some node if there is a cycle

bool hasCycle(ListNode *head) {
        
        ListNode *fast = head,*slow=head;    
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)          // if they ever meet, then loop is present
                return true;
            
        }
        
        return false;      // if we came outside the loop, then loop is not present
        
    }