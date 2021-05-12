// we have to find first non-repating charcter at each instance

// the idea here is to take a queue to maintain the sequence of charcters so that we can check for first 
//non-repeating charcter

// and a visited array to maintain the count of their occurence

// and at each iteration push the char in the queue and increment its count and then check for first
// non-pepeating charcter in the queue.


string FirstNonRepeating(string A){
		    
		    queue<char> seq;     // this queue will store the sequence of appearence of the characters
		    
		    vector<int> vis(26,0);     // a visited vector 
		    
		    string ans ="";     // our answer
		    
		    for(auto x : A)
		    {
		        seq.push(x);     // insert the character in the queue
		        
		        vis[x -'a']++;    // increment the count of that character
		        
		        while(!seq.empty())    // check for first non-repeating character
		        {
		            if(vis[seq.front() - 'a'] > 1)
		              seq.pop();
		              
		              else
		              {
		                  ans.push_back(seq.front());
		                  break;
		              }
		        }
		        
		        if(seq.empty())              // if sequence queue is empty, then there is no non-repeating charcter present
		        ans.push_back('#');         // so insering '#' in that case
		        
		        
		    }
		    
		    return ans;
		    
		}