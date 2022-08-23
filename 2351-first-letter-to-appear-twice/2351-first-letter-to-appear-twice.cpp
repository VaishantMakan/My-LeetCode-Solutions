class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char>temp;
        
        char ans;
        for(int i=0; i<s.length(); i++)
        {
            if(temp.find(s[i]) != temp.end())
            {
                ans = s[i];
                break;
            }
            
            temp.insert(s[i]);
        }
        
        return ans;
    }
};