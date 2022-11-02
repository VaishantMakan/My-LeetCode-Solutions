// TC -> O(n^2)
// SC -> O(n)
// Printing the LIS too

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         
        int n = nums.size();
        
        vector<int>dp(n, 1);
        
        vector<int>prev(n);
        
        int maxi = 0;
        int lastIndex = 0;
        
        for(int i=0;i<n;i++)
        {
            prev[i] = i;
            
            for(int j=0;j<i;j++)
            {
                if((nums[j] < nums[i]) && (1 + dp[j] > dp[i]))
                {
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }

            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
        //printing the LIS
        
        vector<int>lis;
        lis.push_back(nums[lastIndex]);
        
        while(prev[lastIndex] != lastIndex)
        {
            lastIndex = prev[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        
        reverse(lis.begin(), lis.end());
        
        for(int i=0;i<lis.size();i++)
            cout<<lis[i]<<" ";
        
        return maxi;
    }
};