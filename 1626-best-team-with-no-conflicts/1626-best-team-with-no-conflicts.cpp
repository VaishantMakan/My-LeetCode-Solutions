// Approach - 1 - Memoization - Top Down 

// class Solution {
// public:
    
//     int helper(vector<pair<int,int>>arr, int n, int index, int prevI, vector<vector<int>>&dp)
//     {
//         if(index >= n)
//             return 0;
        
//         if(dp[index][prevI+1] != -1)
//             return dp[index][prevI+1];
        
//         int take=0;
//         int dontTake = helper(arr, n, index+1, prevI, dp);
        
//         if(prevI == -1 || arr[index].second >= arr[prevI].second)
//             take = arr[index].second + helper(arr, n, index+1, index, dp);
        
//         return dp[index][prevI+1] = max(take, dontTake);
//     }
    
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
//         vector<pair<int,int>>arr;

//         int n=scores.size();
        
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
//         for(int i=0;i<n;i++)
//         {
//             arr.push_back({ages[i], scores[i]});
//         }
        
//         sort(arr.begin(), arr.end());
        
//         int prevI = -1;
//         int index = 0;
//         return helper(arr, n, index, prevI, dp);
        
//     }
// };

// Approach - 2 - Tabular - Bottom Up 

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<pair<int,int>>arr;

        int n=scores.size();
        
        vector<int> dp(n, 0);
        
        for(int i=0;i<n;i++)
        {
            arr.push_back({ages[i], scores[i]});
        }
        
        sort(arr.begin(), arr.end());
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            dp[i] = arr[i].second;
            for(int j=0;j<i;j++)
            {
                if(arr[i].second >= arr[j].second)
                {
                    dp[i] = max(dp[i], dp[j]+arr[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;   
    }
};