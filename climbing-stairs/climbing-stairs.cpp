class Solution {
public:
    
    int helper(int n, int curr, int dp[])
    {
        if(curr==n)
            return 1;
        
        if(curr>n)
            return 0;
        
        if(dp[curr]>-1)
            return dp[curr];
            
        
        int sum1=0;
        if(curr+1 <= n)
            sum1=helper(n,curr+1,dp);
        
        int sum2=0;
        if(curr+2 <= n)
            sum2=helper(n,curr+2,dp);
        
        dp[curr]=sum1+sum2;
        
        return dp[curr];
    }
    
    int climbStairs(int n) {
        
        int *dp = new int[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        
        return helper(n,0,dp);
    }
};