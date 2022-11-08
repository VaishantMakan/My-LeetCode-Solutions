//Variation of LIS 
//Help -> https://www.youtube.com/watch?v=YY8iBaYcc4g&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=46

class Solution {
public:
    
    bool helper(string& s1, string& s2)
    {
        if(s1.length() != s2.length() + 1)
            return false;
        
        int first=0;
        int second=0;
        
        while(first < s1.length())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        
        if(first == s1.length() && second == s2.length())
            return true;
        
        return false;
    }
    
    static bool compare(string& s1, string& s2)
    {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare);
        
        int n = words.size();
        
        vector<int>dp(n, 1);
        
        int maxi = 1;
        
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(helper(words[i], words[prev]) && dp[prev] + 1 > dp[i])   
                {
                    dp[i] = dp[prev] + 1;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};