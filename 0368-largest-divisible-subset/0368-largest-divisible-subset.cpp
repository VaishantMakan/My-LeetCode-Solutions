// help => https://www.youtube.com/watch?v=gDuZwBW9VvM&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=45

class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<int>dp(n, 1);
        vector<int>prev(n);
        
        int maxi=0;
        int lastIndex=0;
        
        for(int i=0;i<n;i++)
        {
            prev[i] = i;
            
            for(int j=0;j<i;j++)
            {
                if((nums[i] % nums[j] == 0) && (dp[j] + 1 > dp[i]))
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int>lds;
        lds.push_back(nums[lastIndex]);
        
        while(prev[lastIndex] != lastIndex)
        {
            lastIndex = prev[lastIndex];
            lds.push_back(nums[lastIndex]);
        }
        
        reverse(lds.begin(), lds.end());
        
        return lds;
    }
};