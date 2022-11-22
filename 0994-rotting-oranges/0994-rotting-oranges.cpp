class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        queue<pair<int, int>>q;
        
        int countR=0;
        int countAll=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    countR++;
                    countAll++;
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                else if(grid[i][j] == 1)
                    countAll++;
            }
        }
        
        if(countR == countAll)
            return 0;
        
        int ans=-1;
       
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            
            for(int i=0;i<sz;i++)
            {
                pair<int,int>p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                // vis[x][y] = 1;
                
                //check directions
                //up
                if(x-1 >= 0 && vis[x-1][y] == 0 && grid[x-1][y] == 1)
                {
                    vis[x-1][y] = 1;
                    q.push({x-1,y});
                    countR++;
                }
                
                //left
                if(y-1 >= 0 && vis[x][y-1] == 0 && grid[x][y-1] == 1)
                {
                    vis[x][y-1] = 1;
                    q.push({x,y-1});
                    countR++;
                }
                
                //right
                if(y+1 < m && vis[x][y+1] == 0 && grid[x][y+1] == 1)
                {
                    vis[x][y+1] = 1;
                    q.push({x,y+1});
                    countR++;
                }
                
                //down
                if(x+1 < n && vis[x+1][y] == 0 && grid[x+1][y] == 1)
                {
                    vis[x+1][y] = 1;
                    q.push({x+1,y});
                    countR++;
                }
                
            }
        }
        
        // cout<<countR<<endl;
        
        if(countR != countAll)
            return -1;
        
        return ans;
    }
};