// same as merge sort for array
// divide the list in two parts and then merge them

//just keep check while dividing the linked list in two parts

ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(!l1 && !l2)
            return NULL;
        
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        ListNode* ans = NULL;   // resultant list
        
        if(l1->val <= l2->val)
        {
            ans = l1;
            ans->next = merge(l1->next, l2);
        }
        
        else
        {
            ans = l2;
            ans->next = merge(l1, l2->next);
        }
        
        return ans;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode *slow = head, *fast = head->next;     // keep check here ... fast is initialized as head->next
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *first = head, *second = slow->next;  // heads of our two linked lists
        
        slow->next = NULL;           // making null to divide linked list  in two parts
        
        ListNode *l1 = sortList(first);
        ListNode *l2 = sortList(second);
        
        head = merge(l1,l2);
        
        return head;
        
        
        
    }