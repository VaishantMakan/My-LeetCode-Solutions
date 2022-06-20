class Solution {
public:
    
    int helper(vector<int>& nums, int index, int curr, vector<int>& dp)
    {
        if(index >= nums.size())
        {
            return curr;
        }
        
        if(dp[index] != -1)
            return curr + dp[index];
        
        // dont take 
        int ans1 = helper(nums, index+1, curr, dp);
        
        // take 
        int ans2 = helper(nums, index+2, curr+nums[index], dp);
        
        int finalAns = max(ans1, ans2);
        
        return dp[index] = finalAns;
    }
    
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(), -1);
        
        return helper(nums, 0, 0, dp);
        
    }
};