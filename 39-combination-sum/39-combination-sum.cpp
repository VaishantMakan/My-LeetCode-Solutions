class Solution {
public:
    
    vector<vector<int>>ans;
    
    void helper(vector<int>& c, int t, int i, vector<int>& temp)
    {
        
        if(t == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(t < 0)
            return;
        
        if(i >= c.size())
            return;
        
        // option 1 : take the curr element
        temp.push_back(c[i]);
        helper(c, t-c[i], i,temp);
        temp.pop_back();
        
        // option 2 : dont take the curr element
        helper(c, t, i+1,temp);
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        ans.clear();
        
        vector<int> temp;
        
        int index = 0;
        
        helper(candidates, target, index,temp);
        
        return ans;
    }
};