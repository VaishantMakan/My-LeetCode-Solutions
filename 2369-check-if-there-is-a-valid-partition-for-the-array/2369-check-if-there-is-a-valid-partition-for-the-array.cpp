// Three cases :

// check for 2 consicutive are equal
// check for 3 consicutive are equal
// check for 3 increasing numbers

class Solution {
public:
    
    // Recursion + memoisation 
    int helper(vector<int>&nums,int i,vector<int>&dp)
    {
        int n = nums.size();
        
        if(i>=n)      //reached till end
            return 1;
    
        if(dp[i]!=-1) 
            return dp[i];
        
        int p2=0,p3=0;
      
        if(i+1<n)
        {
            p2 = (nums[i]==nums[i+1]);
        }
        if(i+2<n)
        {
            p3 = ((nums[i]==nums[i+1] && nums[i+1]==nums[i+2]) || (nums[i]+1 == nums[i+1] && nums[i+1]+1==nums[i+2])); 
        }
        
       return dp[i] = min(1, ( p2 * helper(nums,i+2,dp) + p3 * helper(nums,i+3,dp) ) );
        
    }
    
    bool validPartition(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int>dp(n+1,-1);
        
        return helper(nums,0,dp);     
    }
    
};