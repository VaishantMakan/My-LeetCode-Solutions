class Solution {
public:
    
    int helper(vector<int> &nums, int index, int n, vector<int> &dp)
    {
        if(index >= n-1)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int temp=100000;
        
        for(int i=1;i<=nums[index];i++)
        {   
            temp = min(temp, 1+helper(nums, index+i,n,dp));
        }

        dp[index]=temp;
        return temp;
    }
    
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int index=0;
        vector<int>dp(n,-1);
        return helper(nums,index,n,dp);
    }
};