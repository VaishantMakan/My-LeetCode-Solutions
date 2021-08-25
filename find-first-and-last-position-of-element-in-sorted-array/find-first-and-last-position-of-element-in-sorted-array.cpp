class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2,-1);
        
        //first occurrence
        int s=0, e=nums.size()-1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            
            if(target < nums[mid])
                e=mid-1;
            else if(target > nums[mid])
                s=mid+1;
            else
            {
                if(mid==s || nums[mid] != nums[mid-1])
                {
                    ans[0]=mid;
                    break;
                }
                else
                {
                    e=mid-1;
                    ans[0]=e;
                }
            }
        }
        
        //last occurrence
        s=0, e=nums.size()-1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            
            if(target < nums[mid])
                e=mid-1;
            else if(target > nums[mid])
                s=mid+1;
            else
            {
                if(mid==e || nums[mid] != nums[mid+1])
                {
                    ans[1]=mid;
                    break;
                }
                else
                {
                    s=mid+1;
                    ans[1]=e;
                }
            }
        }
        
        return ans;
        
    }
};