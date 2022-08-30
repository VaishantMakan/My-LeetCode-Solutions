class Solution {
public:
    
    int helper(int t, vector<int>& coins, int i, int curr, vector<vector<int>>& dp)
    {
        if(curr == t)
            return 1;
        
        if(curr > t || i >= coins.size())
            return 0;
        
        if(dp[i][curr] != -1)
            return dp[i][curr];
        
        return dp[i][curr] = helper(t, coins, i+1, curr, dp) + helper(t, coins, i, curr+coins[i], dp);
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>>dp(n, vector<int>(5001, -1));
        
        return helper(amount, coins, 0, 0, dp);
    }
};