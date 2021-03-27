// we can just simply count the no of 1's, 0's and 2's in one iteration and just store these in the array in sec iteration

// But we have to do it in one pass with 0(1) complexity

// we can use 3 pointers for 0,1,2 and just do it easily

// the whole loop revolves around the mid

 void sort(vector<int>& a) {
        
        int low = 0, mid = 0, high = a.size()-1;         // both low and mid are intialized to 0
        
        while(mid<=high)
        {
            if(a[mid]==0)
                swap(a[low++],a[mid++]);
            
            else if(a[mid]==1)
                mid++;
            
            else
                swap(a[mid],a[high--]);
        }
        
    }