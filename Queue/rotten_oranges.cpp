int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int total_one = 0;
        
        int ans = 0;       // our final answer
        
        queue<vector<int>> q;   // 0 = i, 1 = j, 2 = time
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)       // store intital rotten ones in the queue
                    q.push({i,j,0});
                
                else if(grid[i][j] == 1)     // count the no of 1 for further use
                    total_one++;
                
            }
            
        }
        
        
        int dx[] = {0,0,-1,1};          // two arrays to save lines of code for checking
        int dy[] = {-1,1,0,0};
        
        int total_count_one = 0;
        
        
        while(!q.empty())
        {
            vector<int> temp = q.front();      // take the first element from the queue for operation
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int x = temp[0] + dx[i];
                int y = temp[1] + dy[i];
                
                
                if(x<0 || y<0 || x>=m || y>=n || grid[x][y] != 1)
                    continue;
                
                total_count_one++;          // if we reach here, then we have a cell with 1 in it
                grid[x][y] = 2;
                
                ans = max(ans, temp[2]+1);
                q.push({x,y,temp[2]+1});
                
            }
        }
        
        
        if(total_one != total_count_one)
            return -1;
        
        return ans;
        
    }



    // ## my 100 question on leetcode