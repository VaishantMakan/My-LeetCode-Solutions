class Solution {
public:
    
    int helper(vector<int>& coins, int index, int amount, vector<vector<int>>& dp)
    {
        if(amount == 0)
            return 0;
        
        if(amount < 0)
            return INT_MAX-1;
        
        if(index >= coins.size())
            return INT_MAX-1;
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        return dp[index][amount] = min(1+helper(coins, index, amount-coins[index], dp) , helper(coins, index+1, amount, dp));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int index=0;
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        
        int ans = helper(coins, index, amount, dp);
        
        if(ans == INT_MAX-1)
            return -1;
        else
            return ans;
    }
};