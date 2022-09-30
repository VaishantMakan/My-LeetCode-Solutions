class Solution {
public:
    
    int helper(string& s, string& t, int i, int j, vector<vector<int>>& dp)
    {
        if((i >= s.length() && j >= t.length()) || j >= t.length())
            return 1;
        
        if(i >= s.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //take
        int take=0;
        if(s[i] == t[j])
            take = helper(s, t, i+1, j+1, dp);
        
        int dont = helper(s, t, i+1, j, dp);
        
        return dp[i][j] = take + dont;
    }
    
    int numDistinct(string s, string t) {
        
        int i=0, j=0;
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        return helper(s, t, i, j, dp);
    }
};