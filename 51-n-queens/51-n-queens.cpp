class Solution {
public:
    
    bool check(vector<string>curr, int n, int row, int col)
    {
        //check column
        for(int i=0;i<n;i++)
        {
            if(i==row)
                continue;
            
            if(curr[i][col] == 'Q')
                return false;
        }
        
        //check left diagonal
        //going up 
        int tempI=row-1, tempJ= col-1;
        while(tempI >= 0 && tempJ >=0)
        {
            if(curr[tempI][tempJ] == 'Q')
                return false;
            
            tempI--;
            tempJ--;
        }
        //going down
        tempI=row+1;
        tempJ= col+1;
        while(tempI < n && tempJ < n)
        {
            if(curr[tempI][tempJ] == 'Q')
                return false;
            
            tempI++;
            tempJ++;
        }
        
        //check right diagonal
        //going up
        tempI=row-1;
        tempJ= col+1;
        while(tempI >= 0 && tempJ < n)
        {
            if(curr[tempI][tempJ] == 'Q')
                return false;
            
            tempI--;
            tempJ++;
        }
        
        //going down
        tempI=row+1;
        tempJ= col-1;
        while(tempI < n && tempJ >= 0)
        {
            if(curr[tempI][tempJ] == 'Q')
                return false;
            
            tempI++;
            tempJ--;
        }
        
        return true;
    }
    
    vector<vector<string>> helper(vector<vector<string>>&ans, int n, int index, vector<string>curr)
    {
        if(index >= n)
        {
            ans.push_back(curr);
            return ans;
        }
        
        for(int i=0; i<n; i++)
        {
            curr[index][i] = 'Q';
            if(check(curr, n, index, i))
            {
                ans = helper(ans,n,index+1,curr);
            }
            curr[index][i] = '.';
        }
        return ans;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>curr;
        
        for (int i = 0; i < n; i++)
	    {
		    string temp = "";
		    for (int j = 0; j < n; j++)
		    {
			    temp.append(1, '.');
		    }
		    curr.push_back(temp);
	    }
        
        vector<vector<string>>ans;
        int index=0;
        
        ans = helper(ans, n, index, curr);
        
        return ans;
    }
};