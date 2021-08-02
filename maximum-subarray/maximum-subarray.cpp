class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        int flag=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                flag=1;
                break;
            }
        }
        
        if(flag==0)
        {
            int max=INT_MIN;
            for(int i=0;i<n;i++)
            {
                if(nums[i]>max)
                    max=nums[i];
            }
            return max;
        }
        
        int max_so_far=0;
        int max_ending_here=0;
        
        for(int i=0;i<n;i++)
        {
            max_ending_here += nums[i];
            if(max_ending_here < 0)
                max_ending_here=0;
            
            if(max_ending_here > max_so_far)
                max_so_far=max_ending_here;
        }
        
        return max_so_far;
    }
};