//MCM Variation 
// Help : https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52

class Solution {
public:
    
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        
        for(int k=i; k<=j;k++)
        {
            int val = nums[i-1]*nums[k]*nums[j+1] + helper(i, k-1, nums, dp) + helper(k+1, j, nums, dp); 
            maxi = max(maxi, val);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
        
        return helper(1, n, nums, dp);
    }
};