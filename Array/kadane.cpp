// here we have to find max subarray sum (contiguous)

// the very basic sol is to find all the subarrays and find the sum of each and return the max sum => O(n^3)

// but by using kadane's algorithm we can do it in O(n) time

// the whole idea is to maintain a max sum till now and a sum variable
// whenever the value of sum becomes less than zero we makes the value of sum = 0

int maxSubarraySum(int a[], int n){
        
        int max_s = a[0];          // max sum so far
        int sum = 0;               // max ending here
        
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            max_s=max(max_s,sum);
            
            if(sum<0)
            sum=0;
        }
        
        return max_s;
        
    }