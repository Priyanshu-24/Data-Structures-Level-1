int longestValidParentheses(string s) {
        
        stack <int>st;
        
        int pp=0;
        
        st.push(-1);       // first element is used to provide base for next valid substring
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')             // starting of valid substring at '('
                st.push(i);
            
            else            // ending of valid substring at ')'
            {
                st.pop();         // pop the element 
                
                if(st.empty()==false)
                {
                    pp=max(pp,i-st.top());        // the curr idx will be right limit and top will be left limit
                }
                
                else
                    st.push(i);        // if stack becomes empty push the curr idx in stack for base for next valid substring
            }
        }
        
        return pp;