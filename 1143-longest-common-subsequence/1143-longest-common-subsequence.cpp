class Solution {
public:
    
    int helper(string& s1, string& s2, int i, int j, vector<vector<int>>&dp)
    {
        if(i >= s1.length() || j >= s2.length())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //if char matches
        if(s1[i] == s2[j])
        {
            return dp[i][j] = 1 + helper(s1, s2, i+1, j+1, dp);
        }
        
        //dont match 
        return dp[i][j] = max(helper(s1, s2, i+1, j, dp), helper(s1, s2, i, j+1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int i=0, j=0;
        
        vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        
        return helper(text1, text2, i, j, dp);
    }
};