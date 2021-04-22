// we have to find out the largest rectangular area formed by bars in a histogram

// the cache in this question is that the largest area will have atleat one full bar 
// i.e. that particular bar will be the smallest bar in that area


// Now to find out the max area we have to find out the  area by considering each bar as smallest bar one by one
// and return the max of all areas


// For this we have to find out the left limit and right limit of a particular bar 
// ( bar of smaller heights on right and left side both)


// brute force approach is to take a bar and find left and right limit and cal the area => O(n^2) time



// Can be done using stack in O(n) time and O(n) space

// In this whenever we encounter a bar smaller than the previous bar we have found the right limit for bar on the top of stack

// and the left limit will be in the stack for that paricular bar whose area is to be calculated

int largestRectangleArea(vector<int>& heights) {
        
        stack<int>s;
        
        int i = 0;       // index which will represent the right limit of the bar
        
        int area;        // temp area with taking the top as min height rectangle
        
        int max_area = 0;    // final ans
        
        while(i < heights.size())
        {
            if(s.empty() || heights[s.top()] <= heights[i])    // we will push the index as if the curr bar is greater than the bar at top 
                s.push(i++);                                  // ...... right limit will come afterwards
            
            else       // we have encountered a bar of lesser height in the right side (right limit)
            {
                int t = s.top();
                s.pop();
                
                area = heights[t] * (s.empty() ? i : i-s.top()-1);          // calculate the area with top as the smallest bar
                
                max_area = max(max_area, area);
            }
        }
        
        while(!s.empty())
        {
             int t = s.top();
             s.pop();
                
             area = heights[t] * (s.empty() ? i : i-s.top()-1);          // calculate the area with top as the smallest bar
                
             max_area = max(max_area, area);
        }
        
        return max_area;
        
    }
