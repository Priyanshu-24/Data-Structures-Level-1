// The basic approach is to run two loops and find a smaller element on the right side and update profit as their difference
// the max profit will be the answer => O(n^2)

// We can easily do it in O(n) time

// take a look on the min element so far and update the profit as the diff of min element and the given price on the given day
// max of all these profit is our answer

int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int min_price = INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            min_price = min(min_price, prices[i]);
            profit = max(profit, prices[i] - min_price);
        }
        
        return profit;
    }