//help: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/discuss/2831676/C%2B%2B-Java-Python3-Simple-DFS-O(n)

//video: https://www.youtube.com/watch?v=O7Z0kiWVk5c

#define ll long long

class Solution {
public:
    
    ll ans=0;
    
    long long helper(vector<vector<ll>>& adj, int seats, ll node, ll parent, ll persons = 1)
    {
        
        for(auto& it: adj[node])
        {
            if(it == parent)
                continue;
            
            persons += helper(adj, seats, it, node);
        }
        
        if(node != 0)
            ans += (persons)/seats + (persons%seats != 0 ? 1: 0);
        
        return persons;   
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
     
        ll n = roads.size()+1;
        
        vector<vector<ll>>adj(n, vector<ll>());
        
        for(ll i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        helper(adj, seats, 0, 0);
        
        return ans;
    }
};