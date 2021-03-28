// just simple maths

// take an ans vector and initialize it with storing 1

// now run loop from 2 to n for multiplication

// solve function will multiply each element of ans with that x and also add if carry is present in the ans vector

// at last return the reverse array

void solve(int x, vector<int> &ans)
   {
       int carry = 0;
       
       for(int i=0;i<ans.size();i++)
       {
           int pro = x*ans[i] + carry;
           
           ans[i] = pro % 10;
           
           carry = pro / 10;
       }
       
       while(carry)
       {
           ans.push_back(carry % 10);      // if carry present adding carry % 10 to the ans vector
           carry = carry/10;
       }
   }

    vector<int> factorial(int N){
        
        vector<int> ans;
        
        ans.push_back(1);
        
        for(int i=2;i<=N;i++)
        solve(i,ans);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }