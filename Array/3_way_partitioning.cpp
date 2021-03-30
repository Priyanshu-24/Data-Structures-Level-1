// same as sort array with 0,1,2

// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.

// The individual elements of three sets can appear in any order. You are required to return the modified array

vector<int> threeWayPartition(vector <int> A, int a, int b)
{
     int low=0,mid=0,high=A.size()-1;
     
     while(mid<=high)
     {
         if(A[mid]<a)
         swap(A[mid++],A[low++]);
         
         else if(A[mid]>b)
         swap(A[mid],A[high--]);
         
         else
         mid++;
     }
     
     return A;
}