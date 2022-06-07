class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>>ans;
        
        helper(nums, ans, 0);
        
        return ans;
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, int pos)
    {
        if(pos == nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=pos; i<nums.size(); i++)
        {
            swap(nums[pos], nums[i]);
            
            helper(nums, ans, pos+1);
            
            // backtracking 
            swap(nums[pos], nums[i]);
        }
    }
};