// find the middle of linked list

// first approach is count no of nodes and then traverse the nodes till (count/2) + 1 times
// in this we are traversing the list twice

// second method with single traversal

 ListNode* middleNode(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode *fast = head, *slow = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
    }