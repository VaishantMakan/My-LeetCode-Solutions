class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<char>alpha(26, 0);
        
        for(auto& ch: sentence)
        {
            alpha[ch - 'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(alpha[i] == 0)
                return false;
        }
        
        return true;
    }
};