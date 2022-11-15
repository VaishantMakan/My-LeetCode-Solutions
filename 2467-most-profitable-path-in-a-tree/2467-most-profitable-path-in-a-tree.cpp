// help: https://leetcode.com/problems/most-profitable-path-in-a-tree/discuss/2807150/2-DFS-oror-1-DFS-oror-Simple-Approach-oror-C%2B%2B
// help: https://www.youtube.com/watch?v=QBb8zUX2KlY

class Solution {
public:
    
    void calcDistPar(vector<int>& dis, vector<int>& par, int node, vector<vector<int>>& adj, int d, int p)
    {
        par[node] = p;
        dis[node] = d;
        
        for(auto& it: adj[node])
        {
            if(it != p)
            {
                calcDistPar(dis, par, it, adj, d+1, node);
            }
        }
    }
    
    int dfs(int node, vector<vector<int>>& adj, vector<int>& amount, vector<int>& par)
    {
        int sum = amount[node];
        
        int maxi = -1e9;
        
        for(auto& it: adj[node])
        {
            if(it != par[node])
            {
                maxi = max(maxi, dfs(it, adj, amount, par));
            }
        }
        
        // if leaf node
        if(maxi == -1e9)
            return sum;
        
        return sum+maxi;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();
        
        //creating the graph
        vector<vector<int>>adj(n, vector<int>());
        
        for(auto& it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //calculate distance to each node and the parent of each node for alice
        vector<int>dis(n, 0);
        vector<int>par(n);
        
        calcDistPar(dis, par, 0, adj, 0, 0);
        
        //now we will check bob's path.
        //bob will always have a single path possible to reach node 0 since it is a binary tree
        //and on that path we will update the amt values of the node acc to whether bob reaches it first or alice or both 
        int bobD = 0;
        int curr = bob;
        
        while(curr != 0)
        {
            if(dis[curr] > bobD)
            {
                //bob reaches first 
                amount[curr] = 0;
            }
            else if(dis[curr] == bobD)
            {
                amount[curr] /= 2;
            }
            
            curr = par[curr];
            bobD += 1;  
        }
        
        //now we calculate the most optimal path for allice from 0 to a leaf node acc to updates amt values
        return dfs(0, adj, amount, par);
        
    }
};