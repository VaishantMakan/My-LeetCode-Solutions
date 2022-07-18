// DFS + MEMOIZATION 
class Solution {
public:
    
    int helper(int node, int dst, int k, vector<vector<pair<int, int>>>& adj, vector<vector<int>>& dp)
    {
        if(node == dst)
        {
            return 0;
        }
        
        if(k < 0)
            return INT_MAX;
        
        if(dp[node][k] != -1)
            return dp[node][k];
        
        int optimalFromHere = INT_MAX;
        
        for(auto& it: adj[node])
        {
            int temp = helper(it.first, dst, k-1, adj, dp);

            if(temp == INT_MAX)
                continue;

            optimalFromHere = min(optimalFromHere, temp + it.second);
        }
        
        return dp[node][k] = optimalFromHere;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        
        for(auto& it: flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        int ans = helper(src, dst, k, adj, dp);
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};