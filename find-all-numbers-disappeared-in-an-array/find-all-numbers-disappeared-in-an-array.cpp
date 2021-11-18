class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        //since we are given a range and asked to do this ques in O(n) tc and O(1) sc hence
        //using counting sort
        
        int n=nums.size();
        
        vector<int>a(n,0);
        
        for(int i=0;i<n;i++)
        {
            a[nums[i]-1]++;
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};