ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode *curr=head;
        
        while(curr->next)    // as we just need to reach the last node
        {
            if(curr->val==curr->next->val)
            {
                ListNode *temp=curr->next;
                curr->next=curr->next->next;
                delete(temp);
            }
            
            else
                curr=curr->next;
        }
        
        return head;
        
    }