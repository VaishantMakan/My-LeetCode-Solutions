class Solution {
public:
    
//Memoization :
    
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
    
// Tabulation : 
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int take = 0;
                int dontTake = dp[i+1][j+1];
        
                if(j == -1 || nums[i] > nums[j])
                    take = 1 + dp[i+1][i+1];
        
                dp[i][j+1] = max(take, dontTake);
            }
        }
        
        return dp[0][-1+1];
    }
};