class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxLen = 0;
        int sum = 0;
        
        unordered_map<int, int> m;
        
        m[0] = -1; // if sum=0, then we include all elements until index i
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
                sum += 1;
            else
                sum -= 1;
            
            if(m.find(sum) != m.end())
            {
                int prevI = m[sum];
                
                int len = i-prevI;
                
                maxLen = max(maxLen, len);
            }
            else
                m[sum] = i;
        }
        
        return maxLen;
    }
};