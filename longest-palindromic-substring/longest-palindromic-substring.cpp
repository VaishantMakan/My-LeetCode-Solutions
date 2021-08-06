class Solution {
public:
    
// DP Method ....Time : O(n^2) , space : O(1)    
    string longestPalindrome(string s) {
        
        int n=s.size();
        
        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];
        
        if(n==0)
            return "";
        
        //Initialize with false
        memset(dp,0,sizeof(dp));
        
        string ans="";
        ans += s[0];
        
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if(j-i == 1 || dp[i+1][j-1]==true)
                    {
                        //Then it will also a palindrome substring
                        dp[i][j]=true;
                        
                        if(ans.size() < j-i+1)
                        {
                            //Check for Longest Palindrome substring
                            ans = s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
    
    
//  Expand Around Center method .... Time Complexity : O(n^2), space : O(1)
    
//     int expandAroundCenter(string s, int left, int right)
//     {
//         int l = left, r = right;
//         while(l>=0 && r<s.length() && s.at(l)==s.at(r))
//         {
//             l--;
//             r++;
//         }
        
//         return r-l-1;
//     }
    
//     string longestPalindrome(string s) {
    
//         if(s.length() == 1)
//             return s;
        
//         int start=0,end=0;
        
//         for(int i=0;i<s.length();i++)
//         {
//             int len1 = expandAroundCenter(s,i,i);
//             int len2 = expandAroundCenter(s,i,i+1);
//             int len  = max(len1,len2);
//             if(len > end-start)
//             {
//                 start = i-((len-1)/2);
//                 end = i+(len/2);
//             }
//         }
//         return s.substr(start,end-start+1);
        
//     }
//};