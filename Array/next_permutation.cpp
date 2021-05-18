// Algorithm :-

// Firstly find an index from the back such that a[i]<a[i+1] i.e element on left side is smaller than on the right side
// Then we will have two cases 
//    1. if there doesnot exist ant element such that a[i]<a[i+1] => (5,4,3,2,1)
//        then just reverse the array as it is the last permutaion and first permut. is the ans
//    2. If we have found the req. index i
//        then find another index (j) from the back such that a[j]>a[i] and then swap a[i],a[j]
//         then reverse everything after the index i    


// The intution behind the algo is that there is always an increaing sequence in the ending, it can be as small as a single element
// then we have to find the break point where this increasing sequence breaks (i)
// then we swap to make that prefix greater than previous one but we search from the last as we want just the next permutation'
// now we have done with the left side (prefix) and we have to make the right side as lesser in rank as possible
// But we know that after the index i the array is in increasing order, so to find the just the next permutation
// we just reverse the elements after the index i       

void nextPermutation(vector<int>& a) {
        
        int i,j;
        
        for(i = a.size()-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
                break;
        }
        
        if(i<0)
            reverse(a.begin(),a.end());
        
        else
        {
            for(j=a.size()-1;j>i;j--)
            {
                if(a[j]>a[i])
                    break;
            }
            
            swap(a[i],a[j]);
            reverse(a.begin()+i+1,a.end());
        }
        
    }


// We can also solve it using c++ STL  next_permutation

int main()
{
    string s = { "gfg" };

    bool val = next_permutation(s.begin(),s.end());
    
    if (val == false)
        cout << "No Word Possible"<< endl;                 // reverse the string ..... last permutation case
    else
        cout << s << endl;
    return 0;
}    