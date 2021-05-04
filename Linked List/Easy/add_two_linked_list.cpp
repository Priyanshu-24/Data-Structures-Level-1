ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *after = NULL;
        
        while(curr)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        /l1 = reverse(l1);
        /l2 = reverse(l2);
        
        int sum = 0, carry = 0;
        
        ListNode *ans = NULL, *curr = NULL, *temp = NULL;
        // ans = head of new list
        // curr = keep track of current node
        // temp = temp will make our new node and current will points to it
        
        while(l1 || l2)
        {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = (sum>=10 ? 1 : 0);
            sum = sum % 10;
            
            temp = new ListNode(sum);
            
            if(ans == NULL)
                ans = temp;     // head node for new list
            
            else
                curr->next = temp;
            
            curr = temp;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
               
        }
        
        if(carry > 0)
        {
            temp = new ListNode(carry);
            curr->next = temp;
            temp = curr;
            
        }
        
        ans = reverse(ans);
        
        return ans;
        
    }

    // in leetcode the nodes are added in reverse order, so no need of reverse function
