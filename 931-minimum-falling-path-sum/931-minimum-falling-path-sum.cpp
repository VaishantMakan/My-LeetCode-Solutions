class Solution {
public:
    
    int helper(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=n || j<0 || j>=n)
            return INT_MAX;
        
        if(i==n-1)
            return matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = matrix[i][j] + min(helper(matrix, n, i+1, j-1, dp), min(helper(matrix, n, i+1, j, dp), helper(matrix, n, i+1, j+1, dp)));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int mini = INT_MAX;
        
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        for(int i=0;i<n;i++)
        {
            mini = min(mini, helper(matrix, n, 0, i, dp));
        }
        
        return mini;
    }
};