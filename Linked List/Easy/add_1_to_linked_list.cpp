// if we have to add any number to any number, them absolutely we have to add from back side
// as this is a linked list, we cannot traverse it from back, so we will reverse the list for our operation

// Algorithm :-
//  1. Reverse the linked list
//  2. Add one to the last element (here 3 cases arrive)
//      a. if last element < 9, then just add 1 and break
//      b. if last element is > 9, then we have to take the carry 1 and move forward
//      c. if the element is 9, and its next is null (999)
//  3. reverse the resultant list for the required answer


Node* addOne(Node* head)
{
	head = reverse(head);    // step 1

	Node* curr = head;

	while(curr)
	{
		if(curr->next == NULL && curr->data == 9)     // 2.c
		{
			curr->data = 1;
			Node *temp = new Node(0);
			temp->next = head;
			head = temp;
			curr = curr->next;         // break will not be required as this will be the last iteration
		}

		else if(curr->data == 9)           // 2.b
		{
			curr->data = 0;
			curr = curr->next;
		}

		else                     // 2.a
		{
			curr->data = curr->data+1;
			curr = curr->next;
			break;
		}
	}

	head = reverse(head);

	return head;
}