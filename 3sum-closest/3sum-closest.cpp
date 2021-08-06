class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans=INT_MAX;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(ans==0)
                break;
            
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                
                if(abs(target-sum) < abs(ans))
                    ans = target-sum;
                
                if(sum<target)
                    l++;
                else
                    r--;
                
            }
        }
        return target - ans;
    }
};