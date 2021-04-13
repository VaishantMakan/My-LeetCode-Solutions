// O(n^2) Complexity Solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    
                    break;
                }
            }
        }
        return ans;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// O(n) Complexity Solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int>ans;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            long long rem = target-nums[i];
            
            if(m.find(rem) != m.end())
            {
                ans.push_back(m[rem]);
                ans.push_back(i);
            }
            else
            {
                m[nums[i]]=i;
            }
        }
        return ans;
    }
};
