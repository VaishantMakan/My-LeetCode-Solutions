class Solution {
public:
    int solve(string& s,int index,int prev,int &k,vector<vector<int>>& dp){
        if(index>=s.size())return 0;
        
        if(dp[index][prev]!=-1)return dp[index][prev];
        
        int inc=0,notinc=0;
        if(prev==0 || abs(s[index]-prev)<=k){
            inc=1+solve(s,index+1,s[index],k,dp);
        }
        notinc=solve(s,index+1,prev,k,dp);
        
        return dp[index][prev]=max(inc,notinc);
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>>dp (s.size()+1,vector<int>(150,-1));
        return solve(s,0,0,k,dp);
    }
};

// class Solution {
// public:
    
//     int helper(string s, int k, int index, int prev, vector<vector<int>>& dp)
//     {
//         if(index >= s.length())
//             return 0;
        
//         if(dp[prev+1][index] != -1)
//             return dp[prev+1][index];
        
//         int take = 0;
//         int dontTake = 0;
        
//         if(prev == -1 || abs(s[index] - prev) <= k)
//         {
//             // if(prev != -1)
//             // {
//             //     cout<<"hey : "<<s[index] - 'a'<<" "<<s[prev] - 'a'<<endl;
//             // }
//             // cout<<s[index]<<" "<<prev<<endl;
//             take = 1 + helper(s, k, index+1, s[index], dp);
//         }
        
//         dontTake = helper(s, k, index+1, prev, dp);
        
//         return dp[prev+1][index] = max(take, dontTake);
//     }
    
//     int longestIdealString(string s, int k) {
        
//         int n = s.length();
        
//         vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        
//         return helper(s, k, 0, -1, dp);
        
//     }
// };