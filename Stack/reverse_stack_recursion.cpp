// the basic idea behind the reverse function is to pop the first element and reverse the remaining stack
// and then put that top element at the bottom of reversed stack with remaining elements

void reverse(stack &<int>s)
{

    if(s.empty())      // base condition
    	return;

    int ele = s.top();    // store the first element
    s.pop();

    reverse(s);   // reverse the remaining stack

    insert_bottom(s,ele);         // function which inserts ele at the bottom of reversed stack
}


void insert_bottom(stack<int> &s, int ele)
{
    if(s.empty())        // base condition ..... if the stack becomes empty then only we will insert the ele
    {                    // and place all other elements again in the stack
    	s.push(ele);
    	return;
    }

    int temp = s.top();
    s.pop();                    // poping the element for storing in the recursive stack

    insert_bottom(s, ele);

    s.push(temp);       // placing again in the stack
}



// insert_at_bottom function must be placed above reverse function ( placed below here only for better understanding )