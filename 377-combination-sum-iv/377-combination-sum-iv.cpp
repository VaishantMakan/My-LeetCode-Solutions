class Solution {
public:
    
    int ans=0;
    
    int helper(vector<int>& nums, int target, int curr, vector<int>& dp)
    {
        
        if(dp[curr] != -1)
        {
            return dp[curr];
        }
        
        dp[curr] = 0;
     
        for(int i=0;i<nums.size();i++)
        {   
            if(curr + nums[i] < target)
            {
                dp[curr] += helper(nums, target, curr + nums[i], dp);
            }
            
            if(curr + nums[i] == target)
                dp[curr] += 1;
        }
        
        return dp[curr];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1, -1);
        return helper(nums, target, 0, dp);
        
    }
};