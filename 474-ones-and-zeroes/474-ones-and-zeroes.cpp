//its similar to dp 0/1 knapsack problem ....

class Solution {
public:
    
    int solve(vector<string>& strs,int i, int n, int m, vector<vector<vector<int>>> &dp) {

    if(n < 0 || m < 0) return INT_MIN;
        
    if((n ==0 && m == 0) || i == strs.size()) return 0;
        
    if(dp[i][n][m] != -1) return dp[i][n][m];
        
    int ones = 0, zeros = 0;
    for(auto ch: strs[i]) {
        if(ch == '1') ones += 1;
        else zeros += 1;
    }
        
    return dp[i][n][m] = max(1 + solve(strs, i+1, n - ones, m - zeros, dp), solve(strs, i+1, n, m, dp));
        
}
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>> dp(s, vector<vector<int>> (n+1, vector<int>(m+1, -1)));
        return solve(strs, 0, n, m, dp);
    }
};