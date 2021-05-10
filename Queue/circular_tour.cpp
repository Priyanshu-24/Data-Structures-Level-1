int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        int start = 0, end = 1;
        int bal = gas[0] - cost[0];

        
        if(n==1)       // edge case ..... wrong ans given by gfg
        {
            return bal >= 0 ? start : -1;
        }

        
        while(start != end || bal < 0)
        {
            while(bal < 0 && start != end)
            {
                bal -= gas[start] - cost[start];
                
                start = (start+1) % n;
                
                if(start == 0)
                    return -1;
            }
            
            bal += gas[end] - cost[end];
            
            end = (end+1) % n;
        }
        
        return start;
        
    }