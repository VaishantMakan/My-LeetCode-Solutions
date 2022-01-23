// you can do this without using boolean array since in dp array we are storing count which will be positive so u can initialize dp array with -1 value

class Solution {
public:
    
    int helper(vector<int>& nums, int index, int target, int sum, vector<vector<int>>&dp, vector<vector<bool>>&visited)
    {
        if(index >= nums.size())
        {
            if(sum == target)
                return 1;
            else
                return 0;
        }
        
        if(visited[index][sum + 1000] != false)
            return dp[index][sum + 1000];
        
        visited[index][sum + 1000] = true;
        
        return dp[index][sum + 1000] = helper(nums, index+1, target, sum+nums[index], dp, visited) + helper(nums, index+1, target, sum-nums[index], dp, visited);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        int index=0;
        
        int Tsum=0;
        for(int i=0;i<nums.size();i++)
            Tsum += nums[i];
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(2001, 0));
        vector<vector<bool>>visited(nums.size()+1, vector<bool>(2001 , false));
        
        return helper(nums, index, target, sum, dp, visited);
    }
};