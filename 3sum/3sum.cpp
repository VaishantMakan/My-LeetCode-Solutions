class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
//    Using two pointer Method
        int n=nums.size();
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        if(nums.empty())
            return ans;
        
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]>0)
                break;      // all numbers from now on will be greater than 0, no point in continuing
            
            // we have seen this number & combo before; skip
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int last_left=nums[l], last_right=nums[r];
                    
                    // we have seen this number & combo before; skip
                    while(l<r && nums[l]==last_left)
                        l++;
                    
                    while(l<r && nums[r]==last_right)
                        r--;
                }
                else if(sum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
                
            }
        }
        return ans;
    }
};   
        
        
//    Using HashMaps .... same time complexity (O(n^2)) but is slower...
        
//         int n=nums.size();
//         vector<vector<int>>ans;
//         unordered_map<int,int> m;
        
//         sort(nums.begin(),nums.end());
        
//         for (int i = 0; i < n; i++) 
//             m[nums[i]] = i;
        
//         for(int i=0;i<n;i++)
//         {
//             if (nums[i] > 0) break;
            
//             if(i>0 && nums[i]==nums[i-1])
//                 continue;
            
//             for(int j=i+1;j<n;j++)
//             {
//                 if(j!=i+1 && nums[j]==nums[j-1])
//                     continue;
                
//                 if(m[-(nums[i]+nums[j])] > j)
//                 {
//                     ans.push_back({nums[i],nums[j],-(nums[i]+nums[j])});
//                     continue;
//                 }
//             }
//         }
//         return ans;
//     }
// };