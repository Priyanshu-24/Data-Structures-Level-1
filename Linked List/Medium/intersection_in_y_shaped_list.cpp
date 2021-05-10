// we have to find the intersection of y-shaped linked list

// Brute force approach is to run two loops
// Set a pointer to the head of first list in first loop
// and in the second loop check for the whole second list if the pointer of first loop is equal to the pointer of second loop
// Time = O(n*m) and Space = O(1)


// Better solution is to use hashing
// Store the nodes of first linked list in the set 
// and then traverse the second linked list and check any its nodes are present in set or not
// Time = O(n+m) and Space = O(n)


// Optimal solution with Time = O(n+m) and Space = O(1)

// Algorithm :-
// 1. count the no of nodes of both the lists
// 2. and move the longer list head to their difference of the lengths
// 3. and then traverse the lists simultaneously and check for the equal node


int count(ListNode* head)
    {
        int ans = 0;
        
        while(head)
        {
            ans++;
            head = head->next;
        }
        
        return ans;
    }
    
    ListNode* intersection(ListNode* h1, ListNode*h2, int d)
    {
        while(d--)         // moving the pointer to the distance upto their difference
        {
            h1 = h1->next;
        }
        
        while(h1 && h2)
        {
            if(h1 == h2)            // checking first is important, then increment the pointers
                return h1;
            
            h1 = h1->next;
            h2 = h2->next;
            
        }
        
        return NULL;         // if we reach here, then there is no intersection
    }
    
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        
        if(!h1 || !h2)
            return NULL;
        
        int c1 = count(h1);        // step 1
        int c2 = count(h2);
        int d;
        
        if(c1 > c2)            // we will move the longer linked list pointer 
        {
            d = c1-c2;
            return intersection(h1,h2,d);
        }
        
        else
        {
            d = c2 - c1;
            return intersection(h2,h1,d);
        }
        
    }