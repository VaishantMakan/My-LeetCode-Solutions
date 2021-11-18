class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i] > 0 && nums[i] <= n && nums[i] != i+1 && nums[i] != nums[nums[i]-1])
            {
                 swap(nums[i],nums[nums[i]-1]);
            }
            else
            {
                i++;
                continue;
            }
        }
        
        //debugging 
        // for(int i=0;i<n;i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        
        int ans=1;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                flag=1;
                ans = i+1;
                break;
            }
        }
        if(flag)
            return ans;
        else
            return nums[n-1]+1;
    }
};