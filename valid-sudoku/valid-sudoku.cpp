class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<int>> rows(9, unordered_set<int>());
        vector<unordered_set<int>> columns(9, unordered_set<int>());
        vector<unordered_set<int>> box(9, unordered_set<int>());
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                
                int digit = board[i][j]-'0';
                
                if(rows[i].count(digit))
                    return false;
                
                if(columns[j].count(digit))
                    return false;
                
                int boxNum = (i/3)*3 + (j/3);
                
                if(box[boxNum].count(digit))
                    return false;
                
                rows[i].insert(digit);
                columns[j].insert(digit);
                box[boxNum].insert(digit);
            }
        }
        
        return true;
    }
};