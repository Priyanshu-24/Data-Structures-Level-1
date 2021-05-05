// first method is to store the elements in an array or stack and then check

// Optimized approach with O(1) space

// Find the middle of the list and reverse the next half
// now check from starting and from the reversed point for palindrome


bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next)
            return true;
        
        ListNode* fast = head, *slow = head;
        
        while(fast->next && fast->next->next)   // tricky part 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);     // we are saying slow->next not slow
        
        slow = slow->next;     // increment slow for comparision
        
        while(slow)
        {
            if(slow->val != head->val)
                return false;
            
            slow = slow->next;
            head = head->next;
        }
        cout<<1;
        return true;
        
    }