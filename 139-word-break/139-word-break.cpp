class Solution {
public:
    
    bool helper(const string& s, int start, const unordered_set<string>& d, vector<int>& dp) {
        
        if (start == s.size()) {
            return true;
        }
        
        if (dp[start] != -1) 
            return dp[start];
        
        for (int i = start; i < s.size(); ++i) 
        {
            const string sub = s.substr(start, i - start + 1); 
            if (d.count(sub) == 1) 
            {
                if (helper(s, i+1, d, dp)) {
                    dp[start] = 1;
                    return true;
                }
            }
        }
        
        dp[start] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
      
        unordered_set<string> d(wordDict.begin(), wordDict.end());
		
        // Use a vector since we can index from 0 to N. 
		// Possible values in vector are: -1, 0, 1.
        vector<int> dp(s.length(), -1); 
        return helper(s, 0, d, dp);  
    }
};