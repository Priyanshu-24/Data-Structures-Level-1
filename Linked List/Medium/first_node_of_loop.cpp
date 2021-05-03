// first solution is to traverse the list and store each node in a set (unordered_set<Node*>)
// And before inserting check if the node is already present in the set or not
// If the node is already present, then that node will be the first node of the loop and we will return that
// Time : O(n) and Space : O(n)


//Efficient solution is to use Floyd's loop detection algorithm

// in this question, explaining the intution is very important

// let the point where the fast and slow pointers meet in the loop = x

// distance(head, first node of loop) = distance(x, first node of loop)
// draw diagram on paper and refer gfg for better explaination

 ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next)
            return NULL;
        
        ListNode *fast=head,*slow=head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow)
                break;
        }
        
        if(fast!=slow)         // if fast and slow did not meet i.e no cycle => return null
            return NULL;
        
        slow=head;         // place slow to head (x in above explaination)
        
        while(slow!=fast)            
        {
            slow=slow->next;
            fast=fast->next;
        }
            
        return slow;      // return the node where slow = fast
    }