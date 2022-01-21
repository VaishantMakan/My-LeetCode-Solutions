//so the basic idea is that this is a variation of dp 0/1 knapsack problem
//here first we will sum all the elements and check if its sum is odd or even 
//if the sum is odd, then the ans would be false as there is no way to divide an odd number into 2 subsets....
//if the sum is even then we have a possibility. Now since the array has to be divided into 2 subsets only hence, 
//it means that if the sum of the array was say x then the sum of one subset should be x/2. 
//hence just like subset sum problem of dp, find one subset having sum = x/2 bcuz the remaining elements would be
//automatically part of the second subset as the array has to be divided into two subsets completely. 

class Solution {
public:
    
    bool helper(vector<int>& nums, int index, int w, vector<vector<int>> &dp)
    {
        if(w==0)
            return true;
        
        if(index >= nums.size())
            return false;
        
        if(w < 0)
            return false;
        
        if(dp[index][w] != -1)
            return dp[index][w];
        
        if(nums[index] > w)
            return dp[index][w] = helper(nums, index+1, w, dp);
        else
            return dp[index][w] = (helper(nums, index+1, w-nums[index], dp) || helper(nums, index+1, w, dp));
    }
    
    bool canPartition(vector<int>& nums) {
    
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        
        if(sum%2 != 0)
            return false;
        
        int w=sum/2;
        
        int index=0;
        
        int n = nums.size();
        
        vector<vector<int>>dp(n+1, vector<int>(w+1, -1));
        
        return helper(nums, index, w, dp);
    }
};