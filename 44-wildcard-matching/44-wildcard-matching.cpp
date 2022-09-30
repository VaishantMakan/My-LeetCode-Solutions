class Solution {
public:
    
    bool helper(string &s, string &p, int i, int j, vector<vector<int>>& dp)
    {
        //base case 
        if(i >= s.length() && j >= p.length())
            return true;
        else if(i < s.length() && j >= p.length())
            return false;
        else if(i >= s.length() && j < p.length())
        {
            // means i finished but j remaining, eg : '', '***' respectively 
            while(j < p.length())
            {
                if(p[j] != '*')
                    return false;
                
                j++;
            }
            
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = helper(s, p, i+1, j+1, dp);
        else if(p[j] == '*')
        {
            return dp[i][j] = helper(s, p, i+1, j, dp) || helper(s, p, i, j+1, dp);
        }
        else
            return dp[i][j] = false;
    }   
    
    bool isMatch(string s, string p) {
        
        int i=0, j=0;
        
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        return helper(s, p, i, j, dp);
    }
};