class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // using unordered map
        unordered_map<int,int> m;
        
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        
        for(auto i:ransomNote)
        {
            m[i]++;
        }
        
        for(auto i:magazine)
        {
            m[i]--;
        }
        
        for(auto i:m)
        {
            if(i.second > 0)
                return false;
        }
        
        return true;
    }
};