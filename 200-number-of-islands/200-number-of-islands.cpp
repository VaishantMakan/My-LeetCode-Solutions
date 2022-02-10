// basically in this question we need to check the number of components of an disconnected graph 

class Solution {
public:
    
    void helper(int indexI, int indexJ, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[indexI][indexJ] = 1;
        
        //check all 4 directions 
        //up
        if(indexI-1 >=0 && grid[indexI-1][indexJ] != '0' && !visited[indexI-1][indexJ])
            helper(indexI-1, indexJ, grid, visited);
        
        //right
        if(indexJ+1 < grid[0].size() && grid[indexI][indexJ+1] != '0' && !visited[indexI][indexJ+1])
            helper(indexI, indexJ+1, grid, visited);
        
        //down 
        if(indexI+1 < grid.size() && grid[indexI+1][indexJ] != '0' && !visited[indexI+1][indexJ])
            helper(indexI+1, indexJ, grid, visited);
        
        //left
        if(indexJ-1 >=0 && grid[indexI][indexJ-1] != '0' && !visited[indexI][indexJ-1])
            helper(indexI, indexJ-1, grid, visited);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        vector<pair<int,int>> vertices;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    vertices.push_back({i,j});
                }
            }
        }
        
        //checking all the vertices by traversing 
        vector<vector<int>>visited(n, vector<int>(m, 0));
        int ans=0;
        for(int i=0;i<vertices.size();i++)
        {
            int tempI = vertices[i].first;
            int tempJ = vertices[i].second;
            if(!visited[tempI][tempJ])
            {
                ans++;
                helper(tempI, tempJ, grid, visited);
            }
        }
        
        return ans;
    }
};