class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int majEle = nums[0];
        int count = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] == majEle)
            {
                count++;
                continue;
            }
            else if(nums[i] != majEle)
            {
                count--;
                
                if(count == 0)
                    majEle = nums[i+1];
            }
        }
        
        return majEle;
    }
};