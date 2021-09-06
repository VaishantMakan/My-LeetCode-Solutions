class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int index, int n)
    {
        if(index >= n)
        {
            res.push_back(temp);
            return;
        }
        
        //taking 
        temp.push_back(nums[index]);
        helper(nums, res, temp, index+1, n);
        
        //not taking
        temp.pop_back();
        
        while(index+1 < n && nums[index+1] == nums[index])
            index += 1;
        
        helper(nums, res, temp, index+1, n);
    
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int>temp;
        
        helper(nums,res, temp, 0, n);
        
        return res;
    }
};