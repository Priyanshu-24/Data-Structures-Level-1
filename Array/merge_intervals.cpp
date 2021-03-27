// firstly, we have to sort the intervals to obtain them in consecutive order

// take a temp vector to store the merging intervals and initialize it with first interval

// check if the intervals are merging then merge them (if second element of temp >= first element of the given interval)

// or if the intervals are not merging then add that temp to the answer and update temp to that interval

//............. Do Not forget to add the last temp in the answer after the completion of the loop

 vector<vector<int>> mergeIntervals(vector<vector<int>>& merge) {
        
        vector<vector<int>> ans;
        
        if(merge.size()==0)
            return ans;
        
        sort(merge.begin(),merge.end());     // sort intervals
        
        vector<int> temp = merge[0];         // initialize temp with first interval
        
        for(auto x : merge)
        {
            if(temp[1] >= x[0])                   // condition for merging
                temp[1] = max(temp[1],x[1]);
            
            else
            {
                ans.push_back(temp);                 // if not merging add to answer
                temp = x;
            }
        }
        
        ans.push_back(temp);      // do not forget this step
        
        return ans;
        
    }