class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis)
    {
        // vis[node] = 1;
        
        for(auto& it: adj[node])
        {
            if(vis[it] == 0)
            {
                vis[it] = 1;
                dfs(adj, it, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<vector<int>>adj(n, vector<int>());
        
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(n, 0);
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                vis[i] = 1;
                
                dfs(adj, i, vis);
            }
        }
        
        return ans;
    }
};