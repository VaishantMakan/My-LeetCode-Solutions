//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int helper(int w, int wt[], int val[], int i, int n, vector<vector<int>>& dp)
    {
        
        if(i >= n)
            return 0;
            
        if(dp[i][w] != -1)
            return dp[i][w];
            
        //pick
        int pick = 0;
        if(w-wt[i] >= 0)
            pick = val[i] + helper(w-wt[i], wt, val, i+1, n, dp);
            
        int dont = helper(w, wt, val, i+1, n, dp);
        
        return dp[i][w] = max(pick, dont);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>>dp(n, vector<int>(W+1, -1));
       
       return helper(W, wt, val, 0, n, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends