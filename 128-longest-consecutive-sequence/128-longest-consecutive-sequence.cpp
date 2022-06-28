// Help -: https://leetcode.com/problems/longest-consecutive-sequence/discuss/1254638/Short-and-Easy-Solution-w-Explanation-or-O(N)-Solution-with-comments-using-hashset

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end()); // inserting all elements into hashset
	
        int longest = 0;
        
	    for(auto& num : s) 
        {
		    int cur_longest = 1;
		
            // find consecutive elements in the backward and forward direction from num
		
            for(int j = 1; s.count(num - j); j++)
            {
                s.erase(num - j);
                cur_longest++;
            }
		
            for(int j = 1; s.count(num + j); j++) 
            {
                s.erase(num + j);
                cur_longest++;
            }
		
            longest = max(longest, cur_longest);  // update longest to hold longest consecutive sequence till now
	
        }
	
        return longest;
    }
};


// More Optimization : 
// int longestConsecutive(vector<int>& nums) {
// 	unordered_set<int> s(begin(nums), end(nums));
// 	int longest = 0;
// 	for(auto& num : s) {
//         if(s.count(num - 1)) continue;
// 		int j = 1;
// 		while(s.count(num + j)) j++;
// 		longest = max(longest, j);
// 	}
// 	return longest;
// }