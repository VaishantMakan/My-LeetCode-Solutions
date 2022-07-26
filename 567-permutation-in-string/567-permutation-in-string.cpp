
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        unordered_map<char,int>mp;
        
        int matched = 0;
        int s=0;
        
        for(int i=0; i<n; i++)
            mp[s1[i]]++;
        
        for(int e=0; e<m; e++)
        {
            if(mp.find(s2[e]) != mp.end())
            {
                mp[s2[e]]--;
                
                if(mp[s2[e]] == 0)
                    matched++;
            }
            
            if(e-s+1 > n)
            {
                if(mp.find(s2[s]) != mp.end())
                {
                    if(mp[s2[s]] == 0)
                        matched--;
                    
                    mp[s2[s]]++;
                }
                s++;
            }
            
            if(matched == mp.size())
                return true;
        }
        
        return false;
    }
};