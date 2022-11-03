class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int>mp;
        
        for(auto it: words)
        {
            mp[it]++;
        }
        
        int ans=0;
     
        for(auto it: words)
        {
            string rev = it;
            reverse(rev.begin(), rev.end());
            
            if(mp.find(it) != mp.end() && mp.find(rev) != mp.end() && it != rev)
            {
                ans += 4;
                mp[it]--;
                mp[rev]--;
                
                if(mp[it] == 0)
                    mp.erase(it);
                
                if(mp[rev] == 0)
                    mp.erase(rev);
            }
            else if(mp.find(it) != mp.end() && it == rev && mp[it] > 1)
            {
                if(mp[it]%2 == 0)
                {
                    ans += mp[it]*2;
                    mp.erase(it);
                }
                else
                {
                    ans += (mp[it]-1)*2;
                    mp[it] = 1;
                }
            }
   
        }
 
            for(auto x: mp)
            {
                string it = x.first;
                string rev = it;
                reverse(rev.begin(), rev.end());
                if(it == rev)
                {
                   ans += 2;
                    break;
                }
            }
      
        return ans;
    }
};