// Using DFS to detect a cycle in the directed graph 

// we are using visited[i]=0,1,2 values bcuz , suppose we are given eg: 2 -> [[0,1]] , then in this case our adj list will be -> [0: , 1:0] . i.e 0 will have no adj element and 1 will have 0 i.e the graph will be such that there is a single edge from node 1 to node 0 (it is a directed graph) . So if we simply use the concept of visited=0,1; then on first run ill check for node 0 and it will return vis[0] = 1, no cycle , so now ill check node 1 , it will mark vis[1] = 1 and further check its child nodes (adj elements) i.e check 0 , now it will show node 0 as visited since we had visited it in the previous run but in reality acc to the given graph it shouldnt have been visited , hence we would have gotten wrong answer . So that is why we are using 3 values for visited. 


class Solution {
public:
    
    bool checkCycle(vector<vector<int>>&adj, vector<int>&vis, int node)
    {
        if(vis[node]==1)
            return true;
        
        if(vis[node]==0)
        {
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(checkCycle(adj, vis, it))
                    return true;
            }
        }
        
        vis[node]=2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>visited(numCourses, 0);
        
        //visited[i]=0 -> not visited
        //visited[i]=1 -> visited and currently in processing i.e its child nodes are being checked ... if encountered again means cycle present
        //visited[i]=2 -> visited and processed completely. 
        
        vector<vector<int>> adj(numCourses, vector<int>());
        
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
             if(checkCycle(adj, visited, i))
                    return false;
        }
        
        return true;
    }
};