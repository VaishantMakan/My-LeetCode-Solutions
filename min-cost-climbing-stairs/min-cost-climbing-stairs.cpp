class Solution {
public:
    
    int helper(vector<int>&cost, int* dp, int index, int n)
    {
        if(index>=n)
            return 0;
        
        if(index!=-1 && dp[index]!=-1)
            return dp[index];
        
        if(index == -1)
        {
            int temp1=helper(cost,dp,index+1,n);
            int temp2=helper(cost,dp,index+2,n);
            
            if(temp1<=temp2)
            {
                return temp1;
            }
            else
            {
                return temp2;
            }
        }
        
        return dp[index]= cost[index] + min(helper(cost,dp,index+1,n), helper(cost,dp,index+2,n));
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int* dp = new int[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=-1;
    
        return helper(cost,dp,-1,n);
    }
};