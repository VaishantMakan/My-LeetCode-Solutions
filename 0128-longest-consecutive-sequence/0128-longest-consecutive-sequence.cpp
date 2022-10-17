class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int>mp;
        
        int n = nums.size();
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i] - 1) == mp.end())
            {
                int temp=1;
                
                int number = nums[i];
                
                mp.erase(number);
                number = number+1;
                
                while(1)
                {
                    if(mp.find(number) != mp.end())
                    {
                        temp++;
                        int newN = number + 1;
                        mp.erase(number);
                        
                        number = newN;
                    }
                    else
                        break;
                }
                
                ans = max(ans, temp);
                
            }
        }
        return ans;
    }
};