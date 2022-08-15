// Striver's logic 

class Solution {
public:
    
    int helper(int ind, vector<int>& nums, vector<int>& dp)
    {
        if(ind >= nums.size())
            return 0;
    
        if(dp[ind] != -1)
            return dp[ind];
    
        int take = nums[ind] + helper(ind+2, nums, dp);
        int dont = 0 + helper(ind+1, nums, dp);
    
        return dp[ind] = max(take, dont);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
    
        vector<int>dp(n,-1);
        
        vector<int>temp1, temp2;
        
        for(int i=0; i<n;i++)
        {
            if(i != 0)
                temp1.push_back(nums[i]);
            
            if(i != n-1)
                temp2.push_back(nums[i]);
        }
        
        int ans1 = helper(0, temp1, dp);
        
        for(int i=0; i<n; i++)
            dp[i] = -1;
        
        int ans2 = helper(0, temp2, dp);
        
        return max(ans1, ans2);
    }
};