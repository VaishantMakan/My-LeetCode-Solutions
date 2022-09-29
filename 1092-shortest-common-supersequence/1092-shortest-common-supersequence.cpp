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
        
        set<int>for1;
        set<int>for2;
        
        while(i != 0 && j != 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                // lcs += str1[i-1];
                
                for1.insert(i-1);
                for2.insert(j-1);
                
                i -= 1;
                j -= 1;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                    i -= 1;
                else
                    j -= 1;
            }
        }
        
        // reverse(lcs.begin(), lcs.end());
        
        i=0;
        j=0;
        
        while(i < n && j < m)
        {
            bool inStr1 = false;
            bool inStr2 = false;
            
            if(for1.find(i) != for1.end())
                inStr1 = true;
            
            if(for2.find(j) != for2.end())
                inStr2 = true;
            
            if(inStr1 && inStr2)
            {
                lcs += str1[i];
                i++;
                j++;
            }
            else if(inStr1)
            {
                while(inStr2 != true)
                {
                    lcs += str2[j];
                    j++;
                    
                    if(for2.find(j) != for2.end())
                        inStr2 = true;
                }
            }
            else if(inStr2)
            {
                while(inStr1 != true)
                {
                    lcs += str1[i];
                    i++;
                    
                    if(for1.find(i) != for1.end())
                        inStr1 = true;
                }
            }
            else
            {
                lcs += str1[i];
                lcs += str2[j];
                i++;
                j++;
            }
        }
        
        while(i < n)
        {
            lcs += str1[i];
            i++;
        }
        
        while(j < m)
        {
            lcs += str2[j];
            j++;
        }
        
        return lcs;
    }
};