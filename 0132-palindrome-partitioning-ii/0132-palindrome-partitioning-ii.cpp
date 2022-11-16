// help: https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55

class Solution {
public:
    
    bool isPalindrome(string& s, int i, int j)
    {   
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    int helper(string& s, int i, int n, vector<int>& dp)
    {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int mini = 1e9;
        
        for(int j=i; j<n; j++)
        { 
            if(isPalindrome(s, i, j))
            {
                int cost = 1 + helper(s, j+1, n, dp);
                mini = min(mini, cost);
            }
        }
        
        return dp[i] = mini;
    }
    
    int minCut(string s) {
        
        int n = s.length();
        
        vector<int>dp(n, -1);
        
        return helper(s, 0, n, dp) - 1;
    }
};