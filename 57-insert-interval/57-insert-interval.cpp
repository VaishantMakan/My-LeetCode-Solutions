class Solution {
public:
    
    // there can be 3 cases :
    // case 1: when the new interval comes completely before the curr interval
    // case 2: when the new interval comes completely after the curr interval 
    // case 3: when the new interval lies inside the curr interval whether completely or partially
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        
        for(int i=0;i< intervals.size(); i++)
        {
            // case 1 
            if(newInterval[1] < intervals[i][0])
            {
                res.push_back(newInterval);
                newInterval = intervals[i];
            }
            
            // case 2 
            else if(newInterval[0] > intervals[i][1])
            {
                res.push_back(intervals[i]);
            }
            
            //case 3 
            else
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        
        res.push_back(newInterval);
        return res;
    }
};