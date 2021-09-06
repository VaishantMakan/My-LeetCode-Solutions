class Solution {
public:
    
    void helper(vector<vector<int>>& result, vector<int>& nums, int index, int n)
    {
        if(index == n-1)
        {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> seen;
        for(int i=index;i<n;i++)
        { 
            if(seen.find(nums[i]) == seen.end())
            {
                swap(nums[i], nums[index]);
                helper(result,nums,index+1,n);
                swap(nums[i], nums[index]);
                seen.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>result;
    
        int n=nums.size();
        
        helper(result,nums,0,n);
        
        return result;
    }
};