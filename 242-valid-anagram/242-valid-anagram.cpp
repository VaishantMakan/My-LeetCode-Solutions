class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>m;
        
        if(s.length() != t.length())
            return false;
        
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
            m[t[i]]--; //if element was not exisiting then it will add it in map with frequency 0 and then because of -- present it will make it -1
        }
        
        for(auto i:m)
        {
            if(i.second)  // this basically means if its value is anything other than 0
                return false;
        }
        return true;
    }
};