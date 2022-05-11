class Solution {
public:
    
    // using min heap 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
         vector<vector<int>> res;
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        for(int i=0;i<points.size();i++)
            pq.push({(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]),i});
        
        while(k--){
            res.push_back({points[pq.top().second]});
            pq.pop();
        }
        
        return res;
        
    }
};