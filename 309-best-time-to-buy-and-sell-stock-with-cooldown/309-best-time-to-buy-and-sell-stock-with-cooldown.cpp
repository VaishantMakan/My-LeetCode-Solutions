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
        
//         vector<vector<int>>dp(n, vector<int>(2, -1));
        
//         return helper(prices, 0, 1, dp);
        
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
        
        for(int day=n-1; day >= 0; day--)
        {
            for(int buy=1; buy>=0; buy--)
            {
                if(buy)
                {
                    int take = -prices[day] + dp[day+1][0];

                    int notTake = 0 + dp[day+1][1];

                    dp[day][buy] = max(take, notTake);
                }
                else
                {
                    int take = prices[day] + dp[day+2][1];

                    int notTake = 0 + dp[day+1][0];

                    dp[day][buy] = max(take, notTake);
                }
            }
        }
        
        return dp[0][1];
    }
};