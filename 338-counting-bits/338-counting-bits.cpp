class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>dp(n+1, -1);
        dp[0] = 0;
        
        vector<int>ans;
        ans.push_back(0);
        
        for(int i=1;i<=n;i++)
        {
            int count = 0;
            
            if(i%2 != 0)
                count += 1;
            
            if(dp[i/2] != -1)
            {
                count += dp[i/2];
            }
            
            dp[i] = count;
            ans.push_back(count);
        }
        return ans;
    }
};