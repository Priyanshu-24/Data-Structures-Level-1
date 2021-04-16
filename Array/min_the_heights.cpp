// Minimize the maximum difference b/w heights

// refer to the que for better understanding


int getMinDiff(int arr[], int n, int k){
sort(arr, arr+n);

// This will be the answer when we increase or decrease
// all the elements by k. This is a baseline answer.
// We run the loop below to see if we can do better.
int res = (arr[n-1] - arr[0]);

// Logic is to make the small numbers bigger and big numbers
// smaller. Thus, minimising the difference.
int mnm = arr[0] + k;
int mxm = arr[n-1] - k;

// A[0..i] will be increased while A[i+1..] will be decreased.
// Hence A[i]+k could be the new max, A[n-1]-k is the
// current max minus k.
// A[i+1]-k could be the new min, A[0]+k is the
// current min plus k.

for(int i = 0; i < n-1; i++){
// This is same as Minimize the Heights I. But, here
// height can't be negative. Thus, we don't consider
// the buildings of height less than k.
if(arr[i+1] < k) continue;

int cmin = min(mnm, arr[i+1]-k);
int cmax = max(mxm, arr[i]+k);
res = min(res, cmax-cmin);
}

return res;
}

