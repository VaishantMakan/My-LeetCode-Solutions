class Solution {
public:
    
    const long long mod = 1000000007;
    
    long long helper(int n, int i, vector<int>& dp)
    {
        if(i >= n)
        { 
            return 1;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        long long temp1=0, temp2=0;
        
        // take
        temp1 = helper(n, i+2, dp) % mod;
       
        // dont take 
        temp2 = helper(n, i+1, dp) % mod;
        
        return dp[i] = (temp1 + temp2) % mod;
    }
    
    int countHousePlacements(int n) {
        
        long long ans=0;
        
        vector<int> dp(n, -1);
        
        ans = helper(n, 0, dp);
        
        ans = (ans*ans)%mod;
  
        return ans;
    }
};