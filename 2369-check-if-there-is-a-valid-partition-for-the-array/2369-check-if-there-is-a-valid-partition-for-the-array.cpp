// Three cases :

// check for 2 consicutive are equal
// check for 3 consicutive are equal
// check for 3 increasing numbers
// Recursively call for above conditions and use memorisation fo faster execution

class Solution {
public:
    
    bool helper(vector<int>& nums, int index, vector<int>& dp)
    {
        int n = nums.size();
        
        if(index >= n)
            return true;
        
        if(dp[index] != -1)
            return dp[index];
        
        bool two = false;
        bool three = false;
        
        // for two 
        if(index+1 < n)
        {
            two = nums[index] == nums[index+1];
            
            two = two && helper(nums, index+2, dp);
        }
        
        // for three 
        if(index+1 < n && index + 2 < n)
        {
            three = (nums[index] == nums[index+1] && nums[index] == nums[index+2]) || (nums[index]+1 == nums[index+1] && nums[index]+2 == nums[index+2]);
            
            three = three && helper(nums, index+3, dp);
        }
        
        return dp[index] = two || three;
    }
    
    bool validPartition(vector<int>& nums) {
        
        vector<int>dp(nums.size(), -1);
        
        return helper(nums, 0, dp);
    }
};