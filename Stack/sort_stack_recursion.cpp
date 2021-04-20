// the problen is very similar to reverse a stack using recursion

// just we pop the first element sort the remaining stack and add that element in the sorted stack again in a 
// sorted manner which is done by another function just same as insert at bottom


void sortStack(stack<int> &s)
{
	if(s.empty())
		return;

	int ele = s.top();
	s.pop();

	sortStack(s);

	insert_in_sorted_manner(s, ele);
}


void insert_in_sorted_manner(stack<int> &s, int ele)
{
	if(s.empty() || ele > s.top())   // we have to insert in sorted manner so if the ele is gretaer than the 
	{                                // top element or the stack becomes empty i.e. ele is smallest of them all
		s.push(ele);
		return;
	}

	int temp = s.top();          // this states that => (temp > ele)
	s.pop();

	insert_in_sorted_manner(s, ele);    

	s.push(temp);
}