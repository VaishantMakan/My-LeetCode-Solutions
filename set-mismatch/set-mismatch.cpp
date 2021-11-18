class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
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
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
            
        }
        return ans;
        
    }
};