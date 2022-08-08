class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = nums.size();
        
        unordered_map<long long, long long>m;
        
        long long totalPairs = (n * (n-1))/2;
        
        long long goodPairs = 0;
        
        for(int i=0; i<n; i++)
        {
            goodPairs += m[i-nums[i]];
            
            m[i-nums[i]]++;
        }
        
        return totalPairs - goodPairs;
    }
};