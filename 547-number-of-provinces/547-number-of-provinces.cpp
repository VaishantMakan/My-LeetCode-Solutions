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
        int p1 = findParent(u, parent);
        int p2 = findParent(v, parent);
        
        if(p1 == p2)
            return;
        
        if(rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p2] > rank[p1])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int> parent(n);
        vector<int> rank(n);
        
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1; j<n;j++)
            {
                if(isConnected[i][j])
                {
                    findUnion(i, j, parent, rank);
                }
            }
        }
        
        //counting the components
        int comp=0;
        
        for(int i=0; i<n; i++)
        {
            if(parent[i] == i)
                comp++;
        }
        
        return comp;
    }
};