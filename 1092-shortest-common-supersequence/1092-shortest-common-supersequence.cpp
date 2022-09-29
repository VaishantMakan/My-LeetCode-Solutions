// Method 2 

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string lcs = "";
        
        int i=n, j=m;
    
        while(i != 0 && j != 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                lcs += str1[i-1];
                
                // for1.insert(i-1);
                // for2.insert(j-1);
                
                i -= 1;
                j -= 1;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    lcs += str1[i-1];
                    
                    i -= 1;
                }
                else
                {
                    lcs += str2[j-1];
                    
                    j -= 1;
                }
            }
        }
        
        while(i > 0)
        {
            lcs += str1[i-1];
            i--;
        }
        
        while(j > 0)
        {
            lcs += str2[j-1];
            j--;
        }
        
        reverse(lcs.begin(), lcs.end());
        
        return lcs;
    }
};