class Solution {
public:
    
    int helper(vector<int>& prices, int day, int buy, vector<vector<int>>& dp)
    {
        if(day >= prices.size())
            return 0;
        
        if(dp[day][buy] != -1)
            return dp[day][buy];
        
        if(buy)
        {
            int take = -prices[day] + helper(prices, day+1, 0, dp);
            
            int notTake = 0 + helper(prices, day+1, 1, dp);
            
            return dp[day][buy] = max(take, notTake);
        }
        else
        {
            int take = prices[day] + helper(prices, day+2, 1, dp);
            
            int notTake = 0 + helper(prices, day+1, 0, dp);
            
            return dp[day][buy] = max(take, notTake);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>>dp(n, vector<int>(2, -1));
        
        return helper(prices, 0, 1, dp);
    }
};