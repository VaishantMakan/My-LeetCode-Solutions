class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n = s.length();
        while(s.length() != 0 && s.find(part) <n)
        {
            s.erase(s.find(part), part.length());
        }
        
        return s;
    }
};