class Solution {
public:
    
    bool helper(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index == nums.size()-1)
            return true;
        
        if(index >= nums.size())
            return false;
        
        if(nums[index] == 0)
            return false;
        
        if(dp[index] != -1)
            return dp[index];
        
        for(int j=1; j <= nums[index]; j++)
        {
            bool ans = helper(nums, index + j, dp);
            
            if(ans)
                return dp[index] = true;
        }
        
        return dp[index] = false;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, -1);
        
        return helper(nums, 0, dp);
    }
};