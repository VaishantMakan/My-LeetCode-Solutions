class Solution {
public:
    
    int dfs(int n, vector<int>& cuts, int i, int j, vector<vector<int>>&dp)
    {
        if(j-i <= 1)
            return 0;
        
        if(!dp[i][j])
        {
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                dp[i][j]=min(dp[i][j], cuts[j]-cuts[i]+dfs(n,cuts,i,k, dp)+dfs(n,cuts,k,j, dp));
            }
        }
        
        return dp[i][j];
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size()));
        
        return dfs(n, cuts, 0, cuts.size() - 1, dp);
    }
};