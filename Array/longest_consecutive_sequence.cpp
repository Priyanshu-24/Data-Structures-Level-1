 // here we have to find longest consecutive sequence (in gfg sub-sequence is written)

// Brute force is to sort the array and find lenght of longest consecutive sequence => O(nlogn) time

// Better solution for O(n) time and O(n) space using set 

// the idea is to add all elements in the set and then

// check if one less than the no is present in the set or not 

// we are checking for one lesser bcoz it will give us the startting position of the sequence and from their we will
// check for consecutive sequnce


 int longestConsecutive(vector<int>& a) {
        
        unordered_set<int> s;
        
        int ans = 0;
        
        for(int x : a)
            s.insert(x);
        
        for(int x : a)
        {
            if(s.find(x-1)==s.end())   // if one less than the element is not present, then count all consecutive no from here
            {
                int count = 1;
                int no = x;
                
                while(s.find(no+1)!=s.end())
                {
                    count++;
                    no++;
                }
                
                ans = max(ans,count);
            }
    
        }
        
        return ans;
        
    }