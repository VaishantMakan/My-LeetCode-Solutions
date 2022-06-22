class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> m;
        
        for(int i=0;i<n;i++)
        {
            string orignal = strs[i];
            
            sort(strs[i].begin(), strs[i].end());
            
            m[strs[i]].push_back(orignal);
        }
        
        for(auto& it: m)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};