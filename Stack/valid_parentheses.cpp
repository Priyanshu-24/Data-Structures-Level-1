 bool isValid(string str) {
        
        if(str.size()<=1)
            return 0;
        
        stack<char> s;
        s.push('$');              
        
        for(auto x : str)
        {
            if(x =='(' || x =='{' || x == '[')
                s.push(x);
            
            else if( (x == '}' && s.top()=='{') || 
                     (x == ']' && s.top()=='[') || 
                     (x == ')' && s.top()=='('))
                s.pop();
            
            else
                return false;
        }
        
        if(s.top()!='$')
            return false;
        
        
        return true;
        
        
        
    }