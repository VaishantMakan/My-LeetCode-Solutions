#define ll long long

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        ll m = roads.size();
        
        map<ll, ll>mp;
        
        for(ll i=0;i<m;i++)
        {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        
        //sorting the edges by their degrees
        vector<pair<ll, ll>> indeg(n);
        
        for(ll i=0;i<n;i++)
        {
            if(mp.find(i) != mp.end())
                indeg[i] = {mp[i], i};
            else
                indeg[i] = {0, i};
        }
        
        sort(indeg.begin(), indeg.end());
        
        ll imp = 1;
        ll sum=0;
        
        for(ll i=0;i<n;i++)
        {
            sum = sum + (indeg[i].first * imp);
            imp++;
                
        }
        
        return sum;
    }
};