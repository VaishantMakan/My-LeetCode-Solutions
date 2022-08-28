class Solution {
public:
    
    vector<int> topo(vector<vector<int>>& r, int k)
    {
        vector<vector<int>> adj(k+1, vector<int>());
        
        vector<int> indeg(k+1, 0);
        
        for(auto& it: r)
        {
            adj[it[0]].push_back(it[1]);
            
            indeg[it[1]]++;
        }
        
        queue<int>q;
        
        for(int i=1; i<=k; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }
        
        int count=0;
        
        vector<int> order;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            count++;
            
            order.push_back(node);
            
            for(auto& it: adj[node])
            {
                indeg[it]--;
                
                if(indeg[it] == 0)
                    q.push(it);
            }
        }
        
        if(count == k)
            return order;
        else
            return {};
        
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>row = topo(rowConditions, k);
        vector<int>col = topo(colConditions, k);
        
        if(row.size() == 0 || col.size() == 0)
            return {};
        
        unordered_map<int, int>finalR;
        unordered_map<int, int>finalC;
        
        // to get row
        for(int i=0;i<k; i++)
        {
            finalR[row[i]] = i;
        }
        
        //to get final Col 
        for(int i=0;i<k; i++)
        {
            finalC[col[i]] = i;
        }
        
        vector<vector<int>> result(k, vector<int>(k, 0));
        
        for(int i = 1; i <= k; i++) 
        {
            result[finalR[i]][finalC[i]] = i;
        }
        return result;
    }
};