class Solution {
public:
    
    bool isPossibleRow(vector<vector<char>>& board, int &row, char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
            {
                return false;
            }
        }
        return true;
    }
    
    bool isPossibleCol(vector<vector<char>>& board, int &col, char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)
            {
                return false;
            }
        }
        return true;
    } 
    
    bool isPossibleSquare(vector<vector<char>>& board, int &row, int &col, char c)
    {
        int rowIndex = row - (row%3);
        int colIndex = col - (col%3);
        
        for(int i=rowIndex;i<=rowIndex+2;i++)
        {
            for(int j=colIndex;j<=colIndex+2;j++)
            {
                if(board[i][j]==c)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isPossible(vector<vector<char>>& board, int &row, int &col, char c)
    {
        if(isPossibleRow(board,row,c) && isPossibleCol(board,col,c) && isPossibleSquare(board,row,col,c))
        {
            return true;
        }
        return false;
    }
    
    bool findingEmptySpace(vector<vector<char>>& board, int &row, int &col)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool solve(vector<vector<char>>& board) {
        
        int row=0;
        int col=0;
        
        if(!findingEmptySpace(board,row,col))
        {
            return true;
        }
        
        for(int i=1;i<=9;i++)
        {
            if(isPossible(board,row,col,i+'0'))
            {
                board[row][col]=i+'0';
                if(solve(board))
                {
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
        return;
    }
};