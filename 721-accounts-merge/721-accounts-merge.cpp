class Solution {
    
private: 
    unordered_map<string, vector<string>> g; //to store adjacent nodes of the graph
    
    unordered_set<string> seen; // to keep track of emails that we have already seen.
    
    vector<vector<string>> ans; // to store the final ans;
    
public:
    
    void dfs(string email)
    {
        seen.insert(email);
        ans.back().push_back(email);
        
        // checking all adjacent nodes 
        for(auto& adj: g[email])
        {
            if(!seen.count(adj))
            {
                dfs(adj);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        // creating the graph i.e the adjacency list
        for(auto& acc: accounts)
        {
            for(int i=1;i<acc.size()-1;i++)
            {
                g[acc[i]].push_back(acc[i+1]);
                g[acc[i+1]].push_back(acc[i]);
            }
        }
        
        // finding the final ans
        for(auto& acc: accounts)
        {
            if(!seen.count(acc[1]))
            {
                ans.push_back({acc[0]});
                dfs(acc[1]);
                sort(ans.back().begin()+1, ans.back().end());
                // since the emails are to be sorted not the name i.e at the first position.
            }
        }
        
        return ans;
    }
};