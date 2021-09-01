class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        helper(ans,nums,0);
        
        return ans;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, int pos){
        
        if(pos == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            swap(nums[pos], nums[i]);
            helper(res, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};