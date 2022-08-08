class Solution {
public:
    
    int helper(string& s, int& k, int index, int prev, vector<vector<int>>& dp)
    {
        if(index >= s.length())
            return 0;
        
        if(dp[prev+1][index] != -1)
            return dp[prev+1][index];
        
        int take = 0;
        int dontTake = 0;
        
        if(prev == -1 || abs(s[index] - prev) <= k)
        {
            take = 1 + helper(s, k, index+1, s[index], dp);
        }
        
        dontTake = helper(s, k, index+1, prev, dp);
        
        return dp[prev+1][index] = max(take, dontTake);
    }
    
    int longestIdealString(string s, int k) {
        
        int n = s.length();
        
        vector<vector<int>>dp(150, vector<int>(n+1,-1));
        
        return helper(s, k, 0, -1, dp);
        
    }
};