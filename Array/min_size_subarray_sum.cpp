// We have to find minimum size subarray such that the sum is equal or greater than the given value ( in gfg only greater is given)
// The very basic approach is find all subarrays and find the minimum length with sum greater or equal to the target

// But we need O(n) time solution which can be done using two pointers 

// take two pointers low and high and run a inner loop till the sum becomes greater than the target
// then update the given value of final ans and decrease the sum with the first value and increase low


int minSubArrayLen(int target, vector<int>& a) {
        
        int low=0,high=0,sum=0,ans=INT_MAX;
        
        while(high < a.size())       
        {
            while(sum < target && high < a.size())    // it will give the feasible ans
                sum += a[high++];
            
            while(sum >= target && low < a.size())   // this will reduce the size of array till the minimum one
            {
                ans = min(ans, high-low);
                sum -= a[low++];
            }
        }
        
        return ans==INT_MAX?0:ans;
        
    }