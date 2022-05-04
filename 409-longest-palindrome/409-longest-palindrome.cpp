class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int>m;
        
        for(auto i : s)
        {
            m[i]++;
        }
        
        int evenS=0;
        int oddExists = 0;
        
        for(auto i : m)
        {
            if(i.second % 2 == 0)
            {
                evenS += i.second;
            }
            else
            {
                evenS += i.second - 1;
                oddExists = 1;
            }
        }
        
        return evenS + oddExists;
    }
};