// class Solution {
// public:
    
//     int helper(vector<int>& nums, int index, int prevI, vector<vector<int>>&dp)
//     {
//         if(index >= nums.size())
//             return 0;
        
//         if(dp[index][prevI+1] != -1)
//             return dp[index][prevI+1];
        
//         int take = 0;
//         int dontTake = helper(nums, index+1, prevI, dp);
        
//         if(prevI == -1 || nums[index] > nums[prevI])
//             take = 1 + helper(nums, index+1, index, dp);
        
//         return dp[index][prevI+1] = max(take, dontTake);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
        
//         vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
//         return helper(nums, 0, -1, dp);
//     }
// };

// Approach - 2 - DP - Bottom Up - Tabular 

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>dp(nums.size(), 0);
        
        int ans = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            dp[i] = 1; 
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};