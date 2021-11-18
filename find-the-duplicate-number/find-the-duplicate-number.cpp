class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i] != i+1)
            {
                if(nums[i]!=nums[nums[i]-1])
                {
                    swap(nums[i],nums[nums[i]-1]);
                }
                else
                {
                    i++;
                    continue;
                }
            }
            else
            {
                i++;
                continue;
            }
        }
        
        return nums[n-1];
    }
};