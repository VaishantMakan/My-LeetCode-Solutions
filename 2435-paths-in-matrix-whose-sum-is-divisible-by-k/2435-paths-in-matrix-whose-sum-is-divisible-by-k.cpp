class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int helper(vector<vector<int>>& grid, int k, int i, int j, int n, int m, vector<vector<vector<int>>>& dp, int curr)
    {
        if(i==n && j==m)
        {
            curr = (curr + grid[i][j])%mod;
            
            if(curr%k == 0)
            {
                // cout<<curr<<endl;
                return 1;
            }
            else
                return 0;
        }
        
        if(i > n || j > m)
        {
            return 0;
        }
        
        if(dp[i][j][curr%k] != -1)
            return dp[i][j][curr%k];
        
        
        
        return  dp[i][j][curr%k] = (helper(grid, k, i, j+1, n, m, dp, (curr + grid[i][j])%mod) + helper(grid, k, i+1, j, n, m, dp, (curr + grid[i][j])%mod))%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        
        return helper(grid, k, 0, 0, n-1, m-1, dp, 0);
    }
};