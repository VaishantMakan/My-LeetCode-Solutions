class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        
        vector<int> dir{0,1,0,-1,0};
        
        queue<pair<int,int>>q;
        
//         int countTotalOranges = 0;
//         int countRottenOranges = 0;
        
        
        // pushing all the initial rotten oranges into the queue
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        
        int countAns=0;
        
        // now counting the levels of the bfs of this graph
        while(!q.empty())
        {
            int qSize = q.size();
            countAns++;
            
            while(qSize--)
            {
                auto it = q.front();
                q.pop();
                
                int x = it.first;
                int y = it.second;
            
                // check adjacent 4 directional elements and add in queue
                for(int i=0;i<4;i++)
                {
                    int newX = x + dir[i];
                    int newY = y + dir[i+1];
                    
                    if(newX >=0 && newX < n && newY >=0 && newY < m && !vis[newX][newY] && grid[newX][newY] == 1)
                    {
                        q.push({newX, newY});
                        vis[newX][newY] = true;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // cout<<vis[i][j]<<" ";
                if(vis[i][j] == false && grid[i][j] == 1)
                    return -1;
            }
            // cout<<endl;
        }
        
        if(countAns == 0)
            return 0;
        
        return countAns-1;
    }
};











