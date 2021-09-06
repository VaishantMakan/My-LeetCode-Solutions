class Solution {
public:
    
    bool helper(vector<vector<char>>& board, string word,vector<vector<bool>>& vis, int n, int m, int i, int j, int index)
    {
        if(board[i][j]==word[index])
        {
            if(index == word.length()-1)
                return true;
            
            vis[i][j]=true;
            
            //left
            if(j-1 >= 0 && vis[i][j-1] == false)
            {
                if(helper(board,word,vis,n,m,i,j-1,index+1))
                    return true;
            }
            
            //up
            if(i-1 >= 0 && vis[i-1][j] == false)
            {
                if(helper(board,word,vis,n,m,i-1,j,index+1))
                    return true;
            }
            
            //right
            if(j+1 < m && vis[i][j+1] == false)
            {
                if(helper(board,word,vis,n,m,i,j+1,index+1))
                    return true;
            }
            
            //down
            if(i+1 < n && vis[i+1][j] == false)
            {
                if(helper(board,word,vis,n,m,i+1,j,index+1))
                    return true;
            }
            
            vis[i][j]=false;
            return false;
        }
        
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(helper(board,word,vis,n,m,i,j,0))
                    return true;
            }
        
        return false;
    }
};