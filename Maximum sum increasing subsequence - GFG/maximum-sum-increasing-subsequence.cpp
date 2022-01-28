// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int helper(int arr[], int n, int prevI, int index, vector<vector<int>>&dp)
	{
	    if(index >= n)
	        return 0;
	        
	    if(dp[index][prevI+1] != -1)
	        return dp[index][prevI+1];
	   
	    if(prevI != -1 && arr[index] <= arr[prevI])
	    {
	        return dp[index][prevI+1] = helper(arr, n, prevI, index+1, dp);
	    }
	    else
	    {
	        return dp[index][prevI+1] = max( arr[index] + helper(arr, n, index, index+1, dp) , helper(arr, n, prevI, index+1, dp));
	    }
	   
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n, vector<int>(n+1, -1));
	    return helper(arr, n, -1, 0, dp);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends