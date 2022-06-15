class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<char>pHash(26, 0); // for string p
        
        vector<char>hash(26, 0);  // for string s 
        
        vector<int> ans;
        
        if(p.size() > s.size())
            return ans;
        
        // Adding char in pHash
        for(int i=0;i<p.size();i++)
        {
            pHash[p[i] - 'a']++;
        }
        
        int left = 0, right = 0;
        int pLen = p.size(), sLen = s.size();
        
        // checking for first window 
        while(right < pLen)
        {
            hash[s[right] - 'a'] += 1;
            right++;
        }
        
        right--;
        
        // now sliding window 
        while(right < sLen)
        {
            if(hash == pHash)
            {
                ans.push_back(left);
                
            }
            
            hash[s[left] - 'a'] -= 1;
            left++;
                
            right++;
            
            if(right < sLen)
                hash[s[right] - 'a'] += 1;
        }
        
        return ans;
    }
};