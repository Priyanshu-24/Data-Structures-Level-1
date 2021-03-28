// Brute force will run three loops

// Better solution for O(n^2) solution

int tripletSum(int a[],int n,int x)
{
    if(n<3)
    return 0;
    
    sort(a,a+n);
    
    for(int i=0;i<n-2;i++)
    {
        int k=i+1,l=n-1;
        
        while(k<l)
        {
            if(a[i]+a[k]+a[l]==x)
            return 1;
            
            else if(a[i]+a[k]+a[l]< x)
            k++;
            
            else
            l--;
        }
    }
    return 0;
}