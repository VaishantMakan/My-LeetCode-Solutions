class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> lastIndex(128,-1);
        int res=0;
        int i=0; // starting index of the window
        
        for(int j=0;j<s.length();j++)
        {
            // j will be the ending index of the window
            
            //first calculating the starting index 
            i = max(i, lastIndex[s[j]]+1);
            
            //calculating window size
            res = max(res, j-i+1);
            
            //calculating the last index of the current char 
            lastIndex[s[j]]=j;
        }
        
        return res;
    }
};