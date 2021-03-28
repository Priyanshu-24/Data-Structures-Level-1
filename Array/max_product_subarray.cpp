// take 3 variables max, min and final product which is our answer and initialize all with first element

// Run loop from 1 to n and check if there is any -ve no then just swap min and max

// update max as max(a[i],max*a[i]) and min as min(a[i],min*a[i])

// update final answer as max of our max or product variable


// ma/mi stores the max/min product of
// subarray that ends with the current number A[i]

int maxProduct(vector<int>& a) {
        
        int ma = a[0];
        int mi = a[0];
        int product = a[0];
        
        for(int i=1;i<a.size();i++)
        {

            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if(a[i]<0)
                swap(mi,ma);
            

            // max/min product for the current number is either the current number itself
           // or the max/min by the previous number times the current one
            ma = max(ma*a[i], a[i]);
            mi = min(mi*a[i],a[i]);
            
            product = max(product,ma);
        }
        
        return product;
        
    }