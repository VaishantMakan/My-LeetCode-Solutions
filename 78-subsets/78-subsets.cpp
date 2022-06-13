class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, set<vector<int>>& s, int index)
    {
        if(s.find(temp) == s.end())
        {
            ans.push_back(temp);
            s.insert(temp);
        }
        
        if(index >= nums.size())
            return;
        
        helper(nums, ans, temp, s, index+1);
        
        temp.push_back(nums[index]);
        helper(nums, ans, temp, s, index+1);
        temp.pop_back();
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        set<vector<int>> s;
        
        vector<int> temp;
        
        helper(nums, ans, temp, s, 0);
        
        return ans;
        
    }
};