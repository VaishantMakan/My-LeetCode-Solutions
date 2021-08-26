class Solution {
public:
    
    void helper(int k, int target, vector<int>&combination, vector<vector<int>>&result, int begin)
    {
        if(target==0 && combination.size()==k)
        {
            result.push_back(combination);
            return;
        }
        
        if(combination.size() >= k)
            return;
        
        for(int i=begin; i<=9 && i<=target; ++i)
        {
            
            combination.push_back(i);
            helper(k,target-i,combination,result,i+1);
            combination.pop_back();   
            
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>result;
        
        vector<int>combination;
        
        int begin=1;
        
        helper(k,n,combination,result,begin);
        
        return result;
        
    }
};
