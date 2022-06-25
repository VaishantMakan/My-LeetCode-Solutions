class Solution {
public:
    
    int small_or_equal(vector<int>& nums, int curr)
    {
        int count = 0;
        
        for (auto &num: nums) 
        {
            if (num <= curr)
                count++;
        }
            
        return count;
    }
    
    int findDuplicate(vector<int>& nums) {
        
        // 'low' and 'high' represent the range of values of the target
        int low = 1, high = nums.size();
        
        int duplicate = -1;
        
        while (low <= high) 
        {
            int curr = (low + high) / 2;
            
            if (small_or_equal(nums, curr) > curr) 
            { 
                duplicate = curr;
                high = curr - 1;
                
            } 
            else 
            {
                low = curr + 1;
            }
        }

        return duplicate;
    }
};