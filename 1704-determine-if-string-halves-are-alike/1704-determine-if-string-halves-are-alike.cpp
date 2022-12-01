class Solution {
public:
    
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            return true;
        else
            return false;
    }
    
    bool halvesAreAlike(string s) {
        
        int n = s.length();
        
        int l=0;
        int r=0;
        
        for(int i=0;i<n/2;i++)
        {
            if(isVowel(s[i]))
                l++;
        }
        
        for(int i=n/2; i<n; i++)
        {
            if(isVowel(s[i]))
                r++;
        }
        
        if(l == r)
            return true;
        else
            return false;
        
    }
};