class Solution {
public:
    
    bool checkPalindrome(string &str, int i, int j)
    {
        while(i<j)
        {
            if(str[i++] != str[j--])
                return false;
        }
        
        return true;
    }

    int helper(string &str, int i, int j, int **dp)
    {
        if(i>=j)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(checkPalindrome(str, i, j))
        {
            dp[i][j]=0;
            return 0;
        }
            
        dp[i][j] = INT_MAX;
        int count=0;
        for(int k=i;k<j;k++)
        {
            
            /*An Optimization: We will make the partition only if the string till the partition 
		    (till Kth position) is a valid palindrome. Because the question states that all 
		    partition must be a valid palindrome. If we dont check this, we will have to 
		    perform recursion on the left subproblem too (solve(str, i, k)) and	we will waste 
		    a lot of time on subproblems that is not required. Without this the code will give
		    correct answer but TLE on big test cases. */
            
            //count=1;
            
            if(checkPalindrome(str, i, k))
            {
                int count = 1+helper(str, k+1, j, dp);
                dp[i][j] = min(dp[i][j], count);                
            }
        }
        
        return dp[i][j];
    }
    
    int minCut(string str) {
        
        // cout<<str.size();
        if(checkPalindrome(str, 0, str.size()-1))
            return 0;
            
        int n=str.size();
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        //int dp[n][n];
        
        int **dp = new int *[n];
        for(int i = 0; i <n; i++)
        {
            dp[i] = new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }
        
        return helper(str, 0, n-1, dp);
        
    }
};