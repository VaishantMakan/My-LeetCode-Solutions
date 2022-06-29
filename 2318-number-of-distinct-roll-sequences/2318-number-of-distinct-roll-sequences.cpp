class Solution {
private:
    
	int mod = 1e9+7;

	int helper(int ind, int prev1, int prev2, int n, vector<vector<vector<int>>> &dp)
    {
		//Base Case
		if(ind == n) 
            return 1;

		if(dp[ind][prev1][prev2] != -1) 
            return dp[ind][prev1][prev2];

		int ans = 0;
        
		for(int i = 1;i <= 6;i++) //Exploring all possible values
        {
            if(prev1 != i && prev2 != i && (prev1 == 0 || __gcd(prev1,i) == 1))
				ans = (ans + helper(ind+1,i,prev1,n,dp))%mod;
        }
        
		return dp[ind][prev1][prev2] = ans;
	}
    
public:
	int distinctSequences(int n) 
    {
		vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(7,vector<int>(7,-1)));
        
		return helper(0,0,0,n,dp);
	}
};