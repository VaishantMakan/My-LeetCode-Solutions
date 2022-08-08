// Why we have taken 150 size for prev in dp array ? => 
// prev can go from i - k to i+k ... since only valid prevs are to be checked since only they will be passed on in recursion
// i could be 'z' (122 - Ascii Value) , k at max could be 25
// so j = i+k = 122 + 25 = 147.  round it off to 150 

//We can even trim down this size to 51 or 52 by sending s[index] - 'a' as prevs as that would scale down ascii values (i) to the range 0 - 25
// hence j = i+k = 26 + 25 = 51 or 52 to be safe 

// why we are sending s[index] instead of index as prev ? => 
// because since index can go from 1 - 10e5 , sending index as prev will mean that prev will also range from 1 - 10e5 , hence means dp array of size n*n 
//hence TC -> O(n*n) ... which is TLE 
// But it can be observed that we need prev to check the condition abs(s[index] - s[prev]) <= k ... that means we just need the char at prev index instead
// of prev index . So we can just simply pass the prev char to improve tc , hence the TC -> O(150 * n) .... it can be further optimized to O(26 * n)

class Solution {
public:
    
    int helper(string& s, int& k, int index, int prev, vector<vector<int>>& dp)
    {
        if(index >= s.length())
            return 0;
        
        if(dp[prev+1][index] != -1)
            return dp[prev+1][index];
        
        int take = 0;
        int dontTake = 0;
        
        if(prev == -1 || abs((s[index] - 'a') - prev) <= k)
        {
            take = 1 + helper(s, k, index+1, s[index] - 'a', dp);
        }
        
        dontTake = helper(s, k, index+1, prev, dp);
        
        return dp[prev+1][index] = max(take, dontTake);
    }
    
    int longestIdealString(string s, int k) {
        
        int n = s.length();
        
        vector<vector<int>>dp(150, vector<int>(n+1,-1));
        
        return helper(s, k, 0, -1, dp);
        
    }
};