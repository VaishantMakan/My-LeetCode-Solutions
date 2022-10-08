class Solution {
public:
    
    int helper(vector<int>& prices, int i, int buy, int n, vector<vector<vector<int>>>& dp)
    {
        if(i >= prices.size() || n==0)
            return 0;
        
        if(dp[i][buy][n] != -1)
            return dp[i][buy][n];
        
        if(buy)
        {
            return dp[i][buy][n] = max(-prices[i] + helper(prices, i+1, 0, n, dp), 0 + helper(prices, i+1, 1, n, dp));
        }
        else
        {
            return dp[i][buy][n] = max(prices[i] + helper(prices, i+1, 1, n-1, dp), 0 + helper(prices, i+1, 0, n, dp));           
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(3, vector<int>(3, -1)));
        return helper(prices, 0, 1, 2, dp);
    }
};