// https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14&ab_channel=takeUforward

class Solution {
public:
    
    int helper(vector<vector<int>>& grid, int n, int m, int r, int c1, int c2, vector<vector<vector<int>>>& dp)
    {
        if(c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN;
        
        if(r == n-1)
        {
            if(c1 == c2)
                return grid[r][c1];
            else
                return grid[r][c1] + grid[r][c2];
        }
        
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int maxi = INT_MIN;
        
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                int value=0;
                
                if(c1 == c2)
                    value = grid[r][c1];
                else
                    value = grid[r][c1] + grid[r][c2];
                
                int temp = helper(grid, n, m, r+1, c1+i, c2+j, dp);
                
                if(temp == INT_MIN)
                    continue;
                else
                    value += temp;
                
                maxi = max(maxi, value);
            }
        }
        
        return dp[r][c1][c2] = maxi;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        return helper(grid, n, m, 0, 0, m-1, dp);
    }
};