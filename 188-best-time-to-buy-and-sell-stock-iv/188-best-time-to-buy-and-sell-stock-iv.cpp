// Intuition -> when k is 2 , then basically we can do => Buy, Sell, Buy, Sell , hence 4 moves 
// and we can see that we buy only on even moves, hence we can eliminate buy variable and calculate using k
// similarly for k = 3 => B, S, B, S, B, S , hence 6 moves ....

class Solution {
public:
    
    int helper(int transactionsLeft, vector<int>& prices, vector<vector<int>>& dp, int day)
    {
        if(day == prices.size() || transactionsLeft == 0)
            return 0;
        
        if(dp[day][transactionsLeft] != -1)
            return dp[day][transactionsLeft];
        
        //no transaction
        int ans1 = helper(transactionsLeft, prices, dp, day+1);
        
        //transaction
        int ans2=0;
        
        bool buy = (transactionsLeft % 2 == 0);
        
        if(buy)
        {
            ans2 = -prices[day] + helper(transactionsLeft-1, prices, dp, day+1);
        }
        else
        {
            ans2 = prices[day] + helper(transactionsLeft-1, prices, dp, day+1);
        }
        
        return dp[day][transactionsLeft] = max(ans1, ans2);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>>dp(n, vector<int>(k*2+1, -1));
        
        return helper(k*2, prices, dp, 0);
    }
};