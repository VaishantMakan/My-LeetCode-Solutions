class Solution {
public:
    
    static bool custom(pair<string, int> a , pair<string, int> b)
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        
        return a.second > b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> ans;
        
        unordered_map<string, int>m;
        
        int n = words.size();
        
        for(int i=0;i<n; i++)
        {
            m[words[i]]++;
        }
        
        vector<pair<string, int>> temp(m.begin(), m.end());
        
        sort(temp.begin(), temp.end(), custom);
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(temp[i].first);
        }
        
        return ans;
    }
};