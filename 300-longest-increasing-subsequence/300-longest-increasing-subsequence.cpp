class Solution {
public:
    
//     int helper(vector<int>& nums, int i, int prev, vector<vector<int>>& dp)
//     {
//         if(i >= nums.size())
//         {
//             return 0;
//         }
        
//         if(dp[i][prev+1] != -1)
//             return dp[i][prev+1];
        
//         //pick
//         int pick=0;
//         if(prev == -1 || (prev != -1 && nums[i] > nums[prev]))
//         {
//             pick = 1 + helper(nums, i+1, i, dp);
//         }
        
//         //not pick 
//         int notPick = helper(nums, i+1, prev, dp);
        
//         return dp[i][prev+1] = max(pick, notPick);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
        
//         vector<vector<int>>dp(nums.size(), vector<int>(nums.size() + 1, -1));
        
//         return helper(nums, 0, -1, dp);
//     }
    

    int helper(vector<int>& nums, int index, int prevI, vector<vector<int>>&dp)
    {
        if(index >= nums.size())
            return 0;
        
        if(dp[index][prevI+1] != -1)
            return dp[index][prevI+1];
        
        int take = 0;
        int dontTake = helper(nums, index+1, prevI, dp);
        
        if(prevI == -1 || nums[index] > nums[prevI])
            take = 1 + helper(nums, index+1, index, dp);
        
        return dp[index][prevI+1] = max(take, dontTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return helper(nums, 0, -1, dp);
    }
};