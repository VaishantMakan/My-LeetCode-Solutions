class Solution {
public:
    
    // BFS Solution : 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image.size() == 0)
            return image;
        
        int oldColor = image[sr][sc];
        
        int m=image.size();
        int n=image[0].size();
        
        vector<vector<int>>visited(m, vector<int>(n, 0));
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            int i=p.first;
            int j=p.second;
            
            //up
            if(i-1 >= 0 && image[i-1][j] == oldColor && !visited[i-1][j])
            {
                visited[i-1][j]=1;
                q.push({i-1,j});
            }
            
            //right
            if(j+1 < n && image[i][j+1] == oldColor && !visited[i][j+1])
            {
                visited[i][j+1]=1;
                q.push({i,j+1});
            }
            
            //down
            if(i+1 < m && image[i+1][j] == oldColor && !visited[i+1][j])
            {
                visited[i+1][j]=1;
                q.push({i+1,j});
            }
            
            //left
            if(j-1 >= 0 && image[i][j-1] == oldColor && !visited[i][j-1])
            {
                visited[i][j-1]=1;
                q.push({i,j-1});
            }
            
            image[i][j] = newColor;
        }
        return image;
    }
    
    // DFS Solution : 
//     void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
//     {
//         if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
//         {
//             return;
//         }
//         image[i][j] = newColor;
//         dfs(image,i-1,j,val,newColor);
//         dfs(image,i+1,j,val,newColor);
//         dfs(image,i,j-1,val,newColor);
//         dfs(image,i,j+1,val,newColor);
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
//     {
//         int val = image[sr][sc];
//         dfs(image,sr,sc,val,newColor);
//         return image;
//     }
};