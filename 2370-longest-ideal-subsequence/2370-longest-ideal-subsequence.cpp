// https://leetcode.com/problems/longest-ideal-subsequence/discuss/2390850/Easy-to-understand-or-DP-or-LIS-or-O(n)

// Similar to longest increasing subsequence with slight modification, consider a DP array of size 26 where each index coresponds to the size of maximum subsequence which ends with the character i (here characters are mapped from 0 - 25, i.e. a -> 0, b -> 1, .... z -> 25).

// Now consider iterating from every character in the string from left to right name this iterator ch
// Now for every ch there is some index (int)ch - 'a' in the DP array say it i
// Now for every j from max(0, i - k) to min(25, i + k) DP[i] = max(DP[i], DP[j] + 1)
// This is, every character that ends with character j can be used to append this character i, with maximum 1 + DP[j] length.

// Here the case where j = i should be taken separately because it might happen that it apear earlier and you might modify it several times.


class Solution {
public:
    int longestIdealString(string s, int k) {
        int DP[26] = {0}, ans = 1;
        
        for (char &ch: s) {
            int i = ch - 'a';
            DP[i] = DP[i] + 1;
            
            for (int j = max(0, i - k); j <= min(25, i + k); j++)
                if (j != i)
                    DP[i] = max(DP[i], DP[j] + 1);
            
            ans = max(ans, DP[i]);
        }
        
        for(auto& it: DP)
            cout<<it<<" ";
        
        return ans;
    }
};