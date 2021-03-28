// We have to find how much water is being trapped 

// inshort we have to find min(left_max, right_max) - a[i] for the water trapped in a given element

// the very basic approach is to find left and right max for each element if exist and then add to the answer
// time = O(n^2)


// Another approach is to use prefix and suffix maximum array to avoid that extra loop
// time = O(n), space = O(n)


// Efficient approach with time = O(n) and O(1) space

// take the check of left max and right max and do accordingly




int trap(vector<int>& a) {
        
        int l = 0;
        int r = a.size()-1;
        int l_max = 0;
        int r_max = 0;
        int ans = 0;
        
        while(l<=r)
        {
            if(a[l] <=a[r])       // this step already states that there exists a tower with greater height than this
            {
                if(a[l] >= l_max)   // if it is largest among all previous once 
                    l_max = a[l];
                
                else
                    ans += (l_max - a[l]);
                
                l++;
            }
            
            else         // a greater height tower is present in left side
            {
                if(a[r] >= r_max)
                    r_max = a[r];
                
                else
                    ans += (r_max - a[r]);
                
                r--;
            }
        }
        
        return ans;
        
    }