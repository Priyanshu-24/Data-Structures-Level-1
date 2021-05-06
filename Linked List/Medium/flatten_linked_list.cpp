// we have given a linked list with two pointers -> next and bottom

// we have flatten it into a single list (i.e in a single line) with taking bottom pointer

// sub-linked lists are in sorted order and we have to maintain the sorted order while merging the linked list

// we will use here merge function like we have used in merge sort

// firstly we will reach to the last list and then we will start merging, and at last we will get our result

Node* merge(Node *a, Node*b)
{
    if(a == NULL)
    return b;
    
    if(b == NULL)
    return a;
    
    Node *result = NULL;
    
    if(a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    
    result->next = NULL;    // make the next of first node as null

    return result;
}
    
Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL)
   return root;
   
   root->next = flatten(root->next);
   
   root = merge(root, root->next);
   
   return root;
}