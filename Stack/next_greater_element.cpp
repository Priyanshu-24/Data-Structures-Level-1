// we have to find the next greater element on the right side of the array

// the brute force approach is to run two loops and check for each element on its right side for the greater element
// O(n^2) time and O(1) space


// we can use stack and can solve this que in O(n) time and O(n) space


//just run loop from right side of array and keep the greater element on the top of the array

vector<int> nextGreaterElement(vector<int>a, int n)
{
	stack<int> s;

	vector<int> ans;

	for(int i=n-1;i>=0;i--)
	{
		while(!s.empty() && s.top() <= a[i])          // we just have to keep the greater element on the top from that particular element in a with index i 
			s.pop();

		if(s.empty())          // if s is empty, means there is no NGE for that element
			ans[i] = -1;          

		else
			ans[i] = s.top();

		s.push(a[i]);
	}

	return ans;
}