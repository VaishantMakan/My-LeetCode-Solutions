class Solution {
public:
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j)
    {
        if(visited[i][j])
            return;
        
        visited[i][j] = true;
        
        //up
        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j])
            dfs(heights, visited, i-1, j);
        
        //right
        if(j+1 < heights[0].size() && heights[i][j+1] >= heights[i][j])
            dfs(heights, visited, i, j+1);
        
        //down
        if(i+1 < heights.size() && heights[i+1][j] >= heights[i][j])
            dfs(heights, visited, i+1, j);
        
        //left
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j])
            dfs(heights, visited, i, j-1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        
        if(heights.size() == 0)
            return ans;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>>pacific(n, vector<bool>(m, false));
        
        vector<vector<bool>>atlantic(n, vector<bool>(m, false));
        
        for(int i=0;i<n;i++)
        {
            dfs(heights, pacific, i, 0);
            
            dfs(heights, atlantic, i, m-1);
        }
        
        for(int j=0;j<m;j++)
        {
            dfs(heights, pacific, 0, j);
            
            dfs(heights, atlantic, n-1, j);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};