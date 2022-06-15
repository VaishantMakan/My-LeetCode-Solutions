class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 0)
            return {};
        
        if(n==1)
            return {0};
        
        vector<vector<int>> adj(n);
        
        vector<int> degree(n, 0);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            
            adj[edges[i][1]].push_back(edges[i][0]);
            
            degree[edges[i][0]] += 1;
            
            degree[edges[i][1]] += 1;
            
        }
        
        queue<int> leafNodes;
        
        vector<int> ans;
        
        // adding all the initial leaf nodes 
        for(int i=0; i < degree.size(); i++)
        {
            if(degree[i] == 1)
                leafNodes.push(i);
        }
        
        // now removing leaf nodes and doing this until only 2 or 1 nodes left 
        while(!leafNodes.empty())
        {
            ans.clear();
            
            int size = leafNodes.size();
            
            // for levels i.e bfs 
            for(int i=0;i<size;i++)
            {
                int curr = leafNodes.front();
                leafNodes.pop();
                
                ans.push_back(curr);
                
                for(auto& neighbour: adj[curr])
                {
                    degree[neighbour] -= 1;
                    
                    if(degree[neighbour] == 1)  //adding current leave nodes
                        leafNodes.push(neighbour);
                }
            }
        }
        
        return ans;
    }
};