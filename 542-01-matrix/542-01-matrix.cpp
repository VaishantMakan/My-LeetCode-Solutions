class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        // queue for BFS 
        queue<pair<int,int>>q;
        
        // directions array : 
        vector<int>dir = {0,1,0,-1,0};
        
        //making changes in the existing array only 
        //when zero encountered we'll put it into queue
        //when one encountered we'll make it -1 as it would need processing
        //count variable to check if whole array has 0 only ....
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                }
                else
                {
                    count++;
                    mat[i][j] = -1;
                }
            }
        }
        
        //now we will traverse the queue until empty and update each element i.e -1
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int currI = it.first;
            int currJ = it.second;
            
            //now we check for its all 4 directions 
            for(int i=0; i<4; i++)
            {
                int newI = currI + dir[i];
                int newJ = currJ + dir[i+1];
                
                if(newI < 0 || newI >=n || newJ < 0 || newJ >= m || mat[newI][newJ] != -1)
                    continue;
                
                mat[newI][newJ] = 1 + mat[currI][currJ];
                
                q.push({newI, newJ});
            }
        }
        
        return mat;   
        
    }
};