class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        
        int n=nums.size();
        
        if(n<4)
            return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-3;i++)
        {
            //checking 
            
            //if target smaller and value larger 
            if(target <=0 && nums[i] > 0)
                break;
            //if nums too larger than target 
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target)
                break;
            //if nums[i] is so small, even the largest elements cannot help reach the sum
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target)
                continue;
            //skip duplicates
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            
            //choosing 2nd element
            for(int j=i+1;j<n-2;j++)
            {
                //checking 
                 //if target smaller and value larger 
                if(nums[i]+nums[j] > 0 && target <=0)
                    break;
                // nums[j] has become too large, no point in continuing
			    if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) 
                    break;
                // nums[j] is so small, even the largest elements cannot help reach the sum
			    if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) 
                    continue; 
                // skip duplicates
			    if (j > i+1 && nums[j] == nums[j-1]) 
                    continue;
                
                //choosing 3rd and 4th elements
                int left=j+1, right=n-1;
                while(left<right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        int last_left=nums[left], last_right=nums[right];
                        while(left < right && last_left==nums[left])
                            left++;
                        while(left < right && last_right==nums[right])
                            right--;
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else
                        right--;
                }
    
            }
        }
        return result;
    }
};