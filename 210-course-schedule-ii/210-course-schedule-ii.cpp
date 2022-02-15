// The idea is to first check if it has a cycle or not ... if not then find the topological sort for this DAG . 

class Solution {
public:
    
    void topoSort(int node, vector<vector<int>>&adj, vector<int>&v, stack<int>&s)
    {
        v[node] = 1;
        
        for(auto it: adj[node])
        {
            if(v[it] == 0)
            {
                topoSort(it, adj, v, s);
            }
        }
        
        s.push(node);
    }
    
    bool cycle(int node, vector<vector<int>>&adj, vector<int>&v)
    {
        if(v[node] == 1)
            return true;
        
        if(v[node] == 0)
        {
            v[node] = 1;
            for(auto it: adj[node])
            {
                if(cycle(it, adj, v))
                    return true;
            }
        }
        
        v[node] = 2;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<vector<int>>adj(n, vector<int>());
        
        for(auto it: prerequisites)
        {
            int u = it[1];
            int v = it[0];
            
            adj[u].push_back(v);
        }
        
        vector<int>v(n,0);
        
        vector<int>ans;
        
        //check if cycle 
        for(int i=0;i<n;i++)
        {
            if(cycle(i, adj, v))
                return ans; 
        }
        
        //find topo sort 
        for(int i=0;i<n;i++)
            v[i]=0;
        
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(!v[i])
                topoSort(i, adj, v, s);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};