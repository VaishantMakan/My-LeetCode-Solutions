#define ll long long

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<ll> deg(n, 0);
        
        for(ll i=0;i<roads.size(); i++)
        {
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        
        sort(deg.begin(), deg.end());
        
        ll sum=0;
        ll imp=1;
        
        for(ll i=0;i<n;i++)
        {
            sum += deg[i]*imp;
            imp++;
        }
        
        return sum;
    }
};