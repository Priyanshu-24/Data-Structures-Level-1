// the first method is to divide the array in two parts and implement stack in the two parts
// but in this method if space is present then also we cannot add a new element

// space optimized version is to start both the stacks from the two extreme points of the array


void twoStacks :: push1(int x)
{
   if(top1<top2-1)         // this step is crucial as to check if the array is fully filled or not
   {
     
       arr[++top1]=x;
   }
}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x)
{
    if(top1<top2-1)
    {
        arr[--top2]=x;
    }
}
   
/* The method pop to pop element from the stack 1 */
//Return the popped element
int twoStacks ::pop1()
{
  if(top1==-1)
  return -1;
  
  return arr[top1--];
}

/* The method pop to pop element from the stack 2 */
//Return the popped element
int twoStacks :: pop2()
{
    if(top2==size)
    return -1;
    
    return arr[top2++];
}
