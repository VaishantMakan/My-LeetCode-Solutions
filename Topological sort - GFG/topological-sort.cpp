// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void helper(int node, vector<int>& vis, vector<int> adj[], vector<int> &st)
	{
	    vis[node]=1;
	    
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            helper(it, vis, adj, st);
	        }
	    }
	    
	    st.push_back(node);
	    
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // stack<int>st;
	    vector<int>vis(V, 0);
	    vector<int>st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            helper(i, vis, adj, st);
	        }
	    }
	    
	    vector<int>ans;
	    for(int i=st.size()-1;i>=0;i--)
	    {
	        ans.push_back(st.at(i));
	       // st.pop();
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends