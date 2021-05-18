// Find all subarray sum and check if sum = 0 or not 

// O(n) time and O(n) solution using set

// we will store prefix sum in the set and if the sum occurs again or the sum = 0 we will get an subarray with 0 sum

// If prefix sum has occured again => 0 sum subarray present as we have reached to that sum again after adding something
// to our sum, which means subarray with 0 sum is present

bool zerosum(int a[],int n)
{
    unordered_set <int>s;
    
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=a[i];            // storing prefix sums
                       
        if(sum==0 || s.find(sum)!=s.end())    // first prefix sum = 0 or prefix sum has occured again
        return true;
        
        s.insert(sum);
    }
    
    return false;
}