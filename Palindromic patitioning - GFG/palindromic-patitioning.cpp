// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool checkPalindrome(string &str, int i, int j)
    {
        while(i<=j)
        {
            if(str[i++] != str[j--])
                return false;
        }
        
        return true;
    }

    int helper(string &str, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=j)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(checkPalindrome(str, i, j))
            return 0;
            
        dp[i][j] = INT_MAX;
        int count=0;
        for(int k=i;k<j;k++)
        {
            count=1;
            
            count += helper(str, i, k, dp) + helper(str, k+1, j, dp) ;
                
            dp[i][j] = min(dp[i][j], count);
        }
        
        return dp[i][j];
    }
    
    int palindromicPartition(string str)
    {
        // code here
        
        if(checkPalindrome(str, 0, str.size()-1))
            return 0;
            
        int n=str.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(str, 0, n-1, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends