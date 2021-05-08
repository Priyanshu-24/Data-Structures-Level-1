// we have to create a clone of a linked list with next and random pointer
// random pointer can point to any of the node

// First solution is to use a map (unordered_map<Node*, Node*> m)

// we will store a new node with corresponding to current node in the map
// like cloneCurr = new Node(curr->data) and then
// i.e m[curr] = cloneCurr 

// key = node of original list 
// value = new created list with same data as current list

// Node traverse the linked list again and adjust the next and random pointer of the new created list
// now return head by adjusting it too


// But we have to do it in O(n) time and O(1) space

// step 1 => make a dummy node bwtween two nodes with the value same as first node

// step 2 => now adjust random pointer of all dummy nodes wrt original linked list

// step 3 => now break the links and make original list as previous and make a new linked list with dummy nodesv

 Node* copyRandomList(Node* head) {
        
        if(!head)
            return NULL;
        
        Node* curr = head;
        
        // step 1
        while(curr)
        {
            Node* temp = curr->next;
            
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            
            curr = temp;
        
        }
        
        curr = head;
        

        // step 2
        while(curr)
        {
            if(curr->next)
                curr->next->random = curr->random ? curr->random->next : curr->random;
            
            curr = curr->next ? curr->next->next : curr->next; 
        }
        
        curr = head;
        Node* res = curr->next;
        
        Node* ans = res;
        
        
        // step 3
        while(curr && res)
        {
            curr->next = curr->next ? curr->next->next : curr->next;
            res->next = res->next ? res->next->next : res->next;
            
            curr = curr->next;
            res = res->next;
        }
        
     return ans;   
        
    }
