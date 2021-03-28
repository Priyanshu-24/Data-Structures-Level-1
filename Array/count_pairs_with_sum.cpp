// Brute force is to run two loops and check

// O(n) solution using map

// Just take a variable x and its value is equal to difference of sum and array element

// Now check if that x is present in map or not
//    if not present, then just increase the value of that array element in the map
//    if present, then increase the value of count to the value x has in the map and also 
//        increase the frequency of the array element

int getPairsCount(int a[], int n, int k) {
        
        int c = 0;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            int x = k-a[i];
            
            if(m[x]==0)
             {
                 m[a[i]]++;
             }
             
             else
             {
                 c+=m[x];
                 m[a[i]]++;
             }
        }
        
        return c;
        
    }