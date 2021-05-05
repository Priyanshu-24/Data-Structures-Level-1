// iterative method

// take three pointers curr, prev and next

Node* reverse(Node* head)
{
	Node *curr = head;  // our current pointer used for iteration
	Node *prev = NULL;  // our previous pointer to store previous node used to change the link
	Node *after = NULL;  // our after pointer to store next node 

	while(curr)
	{
		after = curr->next;    // store the next node

		curr->next = prev;    // remove the previous link and join the new link to previous node 

		prev = curr;    // update prev for next iteration
		curr = after;    // update after for next iteration
	}

	head = prev;

    return head;
}

// only second step is imp and used to update the link, other all steps are used to update the pointers


// recursive method 

// divide the linked list in two parts i.e first node and all other rest nodes
// reverse the rest nodes
// link the rest to first
// update head

Node* reverse(Node* head)
{
	if(head == NULL || head->next == NULL)
		return head;

	//reverse the rest to the list
	Node *rest = reverse(head->next);

	//link rest to first
	head->next->next = head;  // join the second node to first node
	head->next = NULL;         // make the next of last element to next

	head = rest;    // update head

}