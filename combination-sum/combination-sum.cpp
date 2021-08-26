class Solution {
public:
    
    void helper(vector<int>& candidates, int target, vector<int>&combination, vector<vector<int>>&result, int begin)
    {
        if(target==0)
        {
            result.push_back(combination);
            return;
        }
        
        for(int i=begin; i != candidates.size() && candidates[i]<=target; ++i)
        {
            if(i==begin || candidates[i] != candidates[i-1])
            {
                combination.push_back(candidates[i]);
                helper(candidates,target-candidates[i],combination,result,i);
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>>result;
        
        vector<int>combination;
        
        int begin=0;
        
        helper(candidates,target,combination,result,begin);
        
        return result;
    }
};