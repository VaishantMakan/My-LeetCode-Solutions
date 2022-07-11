// Memoization 
class Solution {
public:
    
    int helper(string s, int i, vector<int>& dp)
    {
        if(i == s.length()) //if reached till the end, means valid answer found 
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = 0;
        
        if(s[i] != '0') // string starting with 0 won't be valid , for eg : 06
            ans += helper(s, i+1, dp); //considering single chars like 1,2,3.....9
        
        if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
            ans += helper(s, i+2, dp); //considering double chars like 10,11,.....19 && 20,21,...26
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        
        int n = s.length();
        
        if(n == 0)
            return 0;
        
        vector<int> dp(n+1, -1);
        
        return helper(s, 0, dp);
    }
};