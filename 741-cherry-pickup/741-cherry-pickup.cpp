// Helpful Links : 

// https://www.youtube.com/watch?v=q3-6jaNvj6c&ab_channel=ShivankGoel

// https://leetcode.com/problems/cherry-pickup/discuss/778155/Backtracking-with-Memoisation-C%2B%2B-T.C.%3AO(n3)-A.S.%3A-O(n3)-with-comments-for-better-understanding

// https://www.youtube.com/watch?v=QGfn7JeXK54&ab_channel=takeUforward

// BEST :-> https://leetcode.com/problems/cherry-pickup/discuss/1912865/C%2B%2B-oror-Detailed-Explanation-and-clear-Intuitions-oror-Memoization-oror-DP-oror-Good-Question


class Solution {
public:
    
    int helper(int r1, int c1, int c2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        int r2 = r1+c1-c2; // r1+c1 = r2+c2
        
        if(r1>=n || r2 >= n || c1>=n || c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        
        if(dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];
        
        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];
        
        int ans = grid[r1][c1];
        
        if(c1 != c2 && r2 != r1) // just if(r1 != r2) or if(c1 != c2) would also work since r1+c1 = r2+c2
        {
            ans += grid[r2][c2];
        }
        
        //Now we need to take the max of 4 cases for both traversals
        //1.) Right Right
        //2.) Down Down
        //3.) Right Down
        //4.) Down Right
        
        int temp = max(helper(r1, c1+1, c2+1, n, grid, dp), max(helper(r1+1, c1, c2, n, grid, dp), max(helper(r1, c1+1, c2, n, grid, dp), helper(r1+1, c1, c2+1, n, grid, dp))));
            
        ans += temp;
        
        return dp[r1][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return max(0, helper(0, 0, 0, n, grid, dp));
    }
};