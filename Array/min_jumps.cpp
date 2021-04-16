// we have to find the min no of jumps to reach the end of array 
// value at an index implies max no of jumps we can do

// most optimized approach

// here we will take 3 variables and all our ans depends on them

int minJumps(int a[], int n){
        
        if(n<=1)      // if size of array is 1 or empty
        return 0;
        
        if(a[0]==0)    // if the first index element is 0, then we cannot do any jump
        return -1;
        
        int maxR = a[0];   // variable to take care of max reach from that index

        int jump = 1;        // variable to count the no of jump, basically our answer

        int step = a[0];      // variable to take the count of steps we have or remaining
        
        // we will start from the 1 index 
        for(int i=1;i<n;i++)    
        {
            if(i==n-1)           // if we reached the end, return no of jumps
            return jump;
            
            maxR = max(maxR,i+a[i]);    // update max reach if possible
            
            step--;       // step will decrease at each index
            
            if(step==0)       // if steps are over then we have to take the jump
            {
                jump++;        
                
                if(i>=maxR)       // if we have moved ahead of max reach, then we cannot reach the end
                return -1;
                
                step = maxR-i;         // update step for next iteration
                                      // this cannot be equal to a[i] .....note that
            }
        }
        
        return -1;
    }


    // This can also be solved using DP in O(n^2) space and time