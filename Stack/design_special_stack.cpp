// We have to design a stack that supports push, pop and getMin in just O(1) time


// First approach with O(n) space

//In this we take an auxiliary stack to keep track min element 
// while pushing we just push the min element in the stack s2 by comparings s2 top and element

// pop, getMin and top operations are always performed on non-empty stack (assumed)

class MinStack {
    
    stack<int> s1;    // original stack
    stack<int> s2;    // for min element
    
public:
    /** initialize your data structure here. */
    MinStack() {     
    }
    
    void push(int val) {
        
        s1.push(val);
        
        if(s2.empty() || val < s2.top())           // the only thing to see in this question
            s2.push(val);
        
        else
        {
            int y = s2.top();
            s2.push(y);
        }
        
    }
    
    void pop() {
        
        s1.pop();
        s2.pop();
        
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};



// Optimized version with O(1) space

int min;
stack<int>s;

void push(int x)
{
    //three cases arises

    if(s.empty())
    {
        s.push(x);
        min = x;
    }

    else if(x >= min)
        s.push(x);

    else
    {
        s.push(2*x - min)
        min = x;
    }
}

void pop()    // assuming that pop is performed only on a non-empty stack
{
    if(s.top() >= min)
        s.pop();

    else
    {
        min = 2*min - s.top();
        s.pop();
    }
}

int getMin()
{
    return min;
}
