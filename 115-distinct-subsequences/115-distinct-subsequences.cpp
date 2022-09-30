class Solution {
public:
    
    int helperMemo(string& s, string& t, int i, int j, vector<vector<int>>& dp)
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
            take = helperMemo(s, t, i+1, j+1, dp);
        
        int dont = helperMemo(s, t, i+1, j, dp);
        
        return dp[i][j] = take + dont;
    }
    
    int helperTabulation(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        
        static int MOD = (int)1e9 + 7;
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        
        for(int j=1;j<=m;j++)
            dp[0][j] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
                int take=0;
                
                if(s[i-1] == t[j-1])
                    take = dp[i-1][j-1];
        
                int dont = dp[i-1][j];
        
                dp[i][j] = (take + dont)%MOD;
            }
        }
        
        return dp[n][m];
    }
    
    int numDistinct(string s, string t) {
        
        int i=0, j=0;
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        // return helperMemo(s, t, i, j, dp);
        
        return helperTabulation(s, t);
    }
};