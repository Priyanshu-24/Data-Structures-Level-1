queue<int> reverse(queue<int> q)
{
	solve(q);

	return q;
}

void solve(queue<int> &q)
{
	if(q.empty())
		return;

	int temp = q.front();    // store this for furthur use

	q.pop();

	solve(q);

	q.push(temp);

}