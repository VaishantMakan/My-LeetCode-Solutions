// This is O(N) approach ... 
// what we are doing here is that we are using the concept of unordered_map which is used in ques like prefix sum types, eg: continuous subarray sum etc...
// the main logic is that if i have seen temp = (currElement - diff ) , this temp element before then it means by taking this currElement , the diff is possible by using some prev element , which would be temp here and hence for this currE the longest subsequence possible woild be 1 + longest Subequence Possible with temp (prev element);

class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size();
       
        unordered_map<int, int>m;
        
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            if(m.find(arr[i]-difference) != m.end())
            {
                m[arr[i]] = 1 + m[arr[i]-difference];
            }
            else
            {
                m[arr[i]] = 1;
            }
            
            ans = max(ans, m[arr[i]]);
        }
        
        return ans;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// This is O(N^2) DP Approach and will give TLE since constraints on n are till 1e5;

// class Solution {
// public:
    
//     int helper(vector<int>& arr, int d, int i, int prev, vector<vector<int>>& dp)
//     {
//         if(i >= arr.size())
//             return 0;
        
//         if(dp[i][prev+1] != -1e9)
//             return dp[i][prev+1];
        
//         int dont = helper(arr, d, i+1, prev, dp);
        
//         int pick=0;
//         if(prev == -1 || (prev != -1 && (arr[i] - arr[prev]) == d))
//         {
//             pick = 1 + helper(arr, d, i+1, i, dp);
//         }
        
//         return dp[i][prev+1] = max(dont, pick);
//     }
    
//     int longestSubsequence(vector<int>& arr, int difference) {
        
//         int n = arr.size();
//         vector<vector<int>>dp(n, vector<int>(n+1, -1e9));
        
//         return helper(arr, difference, 0, -1, dp);
//     }
// };