class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left <= right)
        {
            int middle = left + (right-left)/2; // to avoid overflow
            
            if(nums[middle] == target)
                return middle;
            
            else if(nums[middle] > target)
                right = middle-1;
            else
                left = middle+1;
        }
        return -1;
    }
};