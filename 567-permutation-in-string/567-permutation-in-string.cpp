class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>curr(26, 0);
        vector<int>req(26, 0);
        
        int n = s1.size();
        int m = s2.size();
        
        if(n==0 && m==0)
            return true;
        
        if(n > m || n==0)
            return false;
        
        int i=0;
        for(; i<n; i++)
        {
            req[s1[i] - 'a']++;
            curr[s2[i] - 'a']++;
        }
        
        if(curr == req)
            return true;
        
        int s=0;
        
        for(; i<m; i++)
        {
            curr[s2[s] - 'a']--;
            s++;
            
            curr[s2[i] - 'a']++;
            
            if(curr == req)
                return true;
        }
        
        return false;
    }
};