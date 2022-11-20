class Solution {
public:
    
    int helper(vector<int>& arr, int k, int i, int n, vector<int>& dp)
    {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int maxi = -1e9;
        
        int ans=0;
        
        for(int j=i;j<n;j++)
        {
            maxi = max(maxi, arr[j]);
            
            //k condition
            if(j-i+1 <= k)
            {     
                int sum = helper(arr, k, j+1, n, dp);  
                
                sum += (j-i+1)*maxi;
                
                ans = max(ans, sum);
            }
            else
            {
                break;
            }
        }
        
        return dp[i] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        vector<int>dp(n, -1);
        
        return helper(arr, k, 0, n, dp);
    }
};