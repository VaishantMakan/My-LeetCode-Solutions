class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int>s;
        
        int n = nums1.size();
        int m = nums2.size();
        
        //storing the indices of nums2 elements
        unordered_map<int,int>mp;
        
        for(int i=0;i<m;i++)
        {
            mp[nums2[i]]=i;
        }
        
        //using the concept of monotonic stack to store next greater element
        //storing indices in stack instead of values, so that we can store values
        
        vector<int>mono(m, -1);
        
        for(int i=0;i<m;i++)
        {
            if(s.empty() || nums2[s.top()] >= nums2[i])
            {
                s.push(i);
            }
            else
            {
                while(!s.empty() && nums2[s.top()] < nums2[i])
                {
                    mono[s.top()] = nums2[i];
                    s.pop();
                }
                
                s.push(i);
            }
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(mono[mp[nums1[i]]]);
        }
        
        return ans;
    }
};