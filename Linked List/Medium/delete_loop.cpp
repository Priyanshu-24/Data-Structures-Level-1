// We can use hashing as used in finding the first node of loop and check if we get a node that
// is already present in the set then that node will be the first node of the loop
// we can run a loop to last element of cycle and make it or 
// or we can take a prev pointer which stores the curr pointer in each iteration so that
// whenever we find a node that is already present, then we can make prev = null

// Time = O(n) and Space = O(n)

// Optimized version using floyd's loop detection algorithm with Time = O(n) and Space = O(1)

// just remove loop, if present
void removeLoop(Node* head)
    {
        Node *fast = head, *slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow==fast)
            break;
        }
        
        if(slow!=fast)    // return if loop not present 
        return;
        
        slow = head;
        
        if(fast==head)          // edge case in this que, if loop starts from the first node itelf
        {
            while(fast->next!=slow)
            fast=fast->next;
        }
        
        else       
        {
            while(slow->next != fast->next)   // in this check for next 
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        fast->next = NULL;    // remove loop
    }