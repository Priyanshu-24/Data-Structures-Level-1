// we can implement it using two queues

// One method will cost push and another will cost pop
// each of the stack will do only one operation from one side i.e one queue will do push(enqueue) and other will pop(dequeue)

// in queue => addition from rear and deletion from front

// In push costly => q1 (pop) and q2 (push)
// In pop costly  => q1 (push) and q2 (pop)

// where q1 is considered as original stack

// pop costly operation is efficient as there can be atmost ( n(pop operations) == n(push operations))
// whereas push can be more

// code for pop operation costly

// here it is considered pop and top are performed on valid cases

class MyStack {
    queue<int> q1;
    queue<int> q2;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        q1.push(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        int x = q1.front();
        q1.pop();
        
        swap(q1,q2);
        
        return x;
        
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !q1.size();
    }
};
