class Solution {
public:
    
    //Boyer-Moore Majority Voting Algorithm
    int majorityElement(vector<int>& nums) {
        
        int major = nums[0];
        int count = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(count==0)
            {
                count++;
                major = nums[i];
            }
            else if(nums[i] == major)
                count++;
            else
                count--;
        }
        
        // since its a valid input hence no need to confirm the frequency with another traversal 
        return major;
    }
};