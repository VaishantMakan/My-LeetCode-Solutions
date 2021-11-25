class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>>ans;
        vector<int> curr;
        int begin=0;
        helper(ans,candidates,target, curr,begin);
        return ans;
    }
    
    void helper(vector<vector<int>>& a, vector<int>& c, int target, vector<int>& curr, int i)
    {
        if(target == 0)
        {
            a.push_back(curr);
            return;
        }
        
        for(int j=i;j<c.size();j++)
        {
            if(target - c[j] < 0)
            {
                return;
            }
            
            curr.push_back(c[j]);
            helper(a,c,target-c[j],curr,j);
            curr.pop_back();
        }
    }
};