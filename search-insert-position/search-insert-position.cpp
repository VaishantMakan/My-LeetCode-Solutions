class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l=1;
        int h=nums.size();
        int mid=0;
        
        while(l<=h)
        {
            mid =(l+h)/2;
            if(nums[mid-1]==target)
            {
                return mid-1;
            }
            else if(target < nums[mid-1])
            {
                h=mid-1;
                continue;
            }
            else
            {
                l=mid+1;
                continue;
            }
        }
        if(target>nums[mid-1])
            return mid;
        else
            return mid-1;
    }
};