#define ll long long

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        ll length=0;
        ll maxL = 0;
        
        ll n = s.length();
        
        for(ll i=0,j=0;i<n;i++)
        {
            char c = s[i];
            int flag=1;
            
            for(ll k=j;k<i;k++)
            {
                if(s[k] == c)
                {
                    flag=0;
                    j=k+1;
                    i=j-1;
                    break;
                }
            }
            
            if(flag==1)
            {
                length++;
                if(maxL < length)
                {
                    maxL=length;
                }
                continue;
            }
            
           length=0;
        }
        
        return maxL;
    }
};