// we have to find a celebrity such that everyone knows him and he doesnot anyone

// a[i][j] = 1 means i knows j 
// a[i][j] = 0 means i doesnot know j


// we will take a stack and always remove two elements from it untill the size gets equal to 1
// at last we will check that potential candidate for the celebrity

// we will use elimination method and eliminate each candidate in each iteration

// Space = O(n) for stack and time = O(n) => 3(n-1) comparisons

int celebrity(vector<vector<int> >& M, int n) {
        
        stack<int> s;
        
        for(int i=0;i<n;i++)    // push all indices in the stack
        s.push(i);
        
        while(s.size() > 1)
        {
            int a = s.top();       // pop first element
            s.pop();
            
            int b = s.top();      // pop second element
            s.pop();
            
            if(M[a][b] == 1)            // if a knows b => a != celebrity
            s.push(b);
            
            else          // if a does not knows b => b != celebrity
            s.push(a);
            
            
        }
        
        int x = s.top();         // potential candidate for celebrity
        
        for( int i=0;i<n;i++)
        {
            if(i!=x)
            {
                if(M[i][x] == 0 || M[x][i] == 1)
                return -1;
            }
        }
        
        return x;
        
    }

// Note :- there can only be one celebrity which means either we have one celebrity or no celebrity


// this can also be done using two pointers in O(1) space and O(n) time    