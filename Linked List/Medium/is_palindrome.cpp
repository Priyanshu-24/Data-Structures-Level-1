// first method is to store the elements in an array or stack and then check

// Optimized approach with O(1) space

// Find the middle of the list and reverse the next half
// now check from starting and from the reversed point for palindrome


bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next)
            return true;
        
        ListNode* fast = head, *slow = head;
        
        while(fast->next && fast->next->next)   // tricky part as we do need to check the middle element in odd lenght list
        {                                        // and in even length linked we just need a before node from where the list 
            slow = slow->next;                 // is to be reversed
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

        return true;
        
    }