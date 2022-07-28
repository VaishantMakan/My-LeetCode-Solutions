class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0;
        
        while(low < n-1 && nums[low] <= nums[low+1])
            low++;
        
        if(low == n-1)
            return 0;
        
        int high = n-1;
        
        while(high > 0 && nums[high] >= nums[high-1])
            high--;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = low; i <= high; i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        
        while(low > 0 && nums[low-1] > mini)
            low--;
        
        while(high < n-1 && nums[high+1] < maxi)
            high++;
        
        return high-low+1;
    }
};