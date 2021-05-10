queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack <ll>s;
    
    int l=q.size();
    int x=k;
    
    while(k--)
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    for(int i=1;i<=l-x;i++)
    {
        int t=q.front();
        q.pop();
        q.push(t);
    }
    
    return q;
}