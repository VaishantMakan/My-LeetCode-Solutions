//LIS variation 
// help -> https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=49

class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>dp(n, 1);

        int maxi=1;
        int ans=0;
        
        vector<int>count(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    count[i] = count[j];
                    dp[i] = dp[j] + 1;
                }
                else if(nums[j] < nums[i] && dp[j] + 1 == dp[i])
                {
                   count[i] += count[j];
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dp[i] == maxi)
                ans += count[i];
        }

        
        return ans;
    }
};