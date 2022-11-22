//bfs solution

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis)
    {
        vis[i][j] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        //right
        if(j+1 < m && grid[i][j+1] - '0' == 1 && vis[i][j+1] == 0)
            dfs(grid, i, j+1, vis);
        
        //left
        if(j-1 >= 0 && grid[i][j-1] - '0' == 1 && vis[i][j-1] == 0)
            dfs(grid, i, j-1, vis);
        
        //up
        if(i-1 >= 0 && grid[i-1][j] - '0' == 1 && vis[i-1][j] == 0)
            dfs(grid, i-1, j, vis);
        
        //down
        if(i+1 < n && grid[i+1][j] - '0' == 1 && vis[i+1][j] == 0)
            dfs(grid, i+1, j, vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] - '0' == 1 && vis[i][j] == 0)
                {
                    ans++;
                    // vis[i][j] = 1;
                    dfs(grid, i, j, vis);
                }
            }
        }
        
        return ans;
    }
};