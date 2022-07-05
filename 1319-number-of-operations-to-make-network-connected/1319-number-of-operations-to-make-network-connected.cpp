// Union Find Algo with path compression and union by rank optimization 

class Solution {
public:
    
    int findParent(int u, vector<int>& parent)
    {
        if(parent[u] == u)
            return u;
        
        return parent[u] = findParent(parent[u], parent);
    }
    
    void findUnion(int u, int v, vector<int>& parent, vector<int>& rank)
    {
        int parent1 = findParent(u, parent);
        int parent2 = findParent(v, parent);
        
        if(parent1 == parent2)
            return;
        
        if(rank[parent1] > rank[parent2])
        {
            parent[parent2] = parent1;
        }
        else if(rank[parent2] > rank[parent1])
        {
            parent[parent1] = parent2;
        }
        else
        {
            parent[parent1] = parent2;
            rank[parent2]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
            return -1;
        
        vector<int> parent(n);
        vector<int> rank(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(auto& i: connections)
        {
            findUnion(i[0], i[1], parent, rank);
        }
        
        //checking number of components
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i] == i)
                components++;
        }
        
        // since for n components/ nodes, the least number of required wires/ edges = n-1
        return components-1;
    }
};



