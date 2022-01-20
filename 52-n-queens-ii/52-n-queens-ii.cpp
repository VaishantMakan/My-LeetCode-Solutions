//optimized way and fast ....

class Solution {
public:

    int ans=0;
    void solve(int n, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2, int i)
    {
        if(i==n) //last row: solution found
        {
            ans++;
        }
        for(int j=0; j<n; j++)
        {
            int id1=j-i+n;
            int id2=i+j;
            if(cols[j] || d1[id1] || d2[id2]) 
                continue; //present in column, diagonal 1, diagonal 2
            
            cols[j]=true;
            d1[id1]=true;
            d2[id2]=true;
            solve(n, cols, d1, d2, i+1); //solve for next row
            cols[j]=false;
            d1[id1]=false;
            d2[id2]=false;
        }
    }
    int totalNQueens(int n) {
        vector<bool> cols(n, false), d1(2*n, false), d2(2*n, false);
        
        //basically the idea is 
        //every diagonal has a unique integer for itself 
        //for the left diagonal, it is -> (i-j) + (n-1) ... n-1 is added just to avoid negatives 
        //for right diagonal it is -> i+j
        //so whenever you choose a position fill this corresponding position of diagonals and the 
        //column and later check from this only ...
        
        solve(n, cols, d1, d2, 0);
        return ans;
    }
};


//2nd way ... slow 

// class Solution {
// public:
    
//     bool check(vector<string>curr, int n, int row, int col)
//     {
//         //check column
//         for(int i=0;i<n;i++)
//         {
//             if(i==row)
//                 break;
            
//             if(curr[i][col] == 'Q')
//                 return false;
//         }
        
//         //check left diagonal
//         //going up 
//         int tempI=row-1, tempJ= col-1;
//         while(tempI >= 0 && tempJ >=0)
//         {
//             if(curr[tempI][tempJ] == 'Q')
//                 return false;
            
//             tempI--;
//             tempJ--;
//         }
        
//         //check right diagonal
//         //going up
//         tempI=row-1;
//         tempJ= col+1;
//         while(tempI >= 0 && tempJ < n)
//         {
//             if(curr[tempI][tempJ] == 'Q')
//                 return false;
            
//             tempI--;
//             tempJ++;
//         }
        
//         return true;
//     }
    
//     vector<vector<string>> helper(vector<vector<string>>&ans, int n, int index, vector<string>curr)
//     {
//         if(index >= n)
//         {
//             ans.push_back(curr);
//             return ans;
//         }
        
//         for(int i=0; i<n; i++)
//         {
//             curr[index][i] = 'Q';
//             if(check(curr, n, index, i))
//             {
//                 ans = helper(ans,n,index+1,curr);
//             }
//             curr[index][i] = '.';
//         }
//         return ans;
//     }
    
//     int totalNQueens(int n) {
        
//         vector<string>curr;
        
//         for (int i = 0; i < n; i++)
// 	    {
// 		    string temp = "";
// 		    for (int j = 0; j < n; j++)
// 		    {
// 			    temp.append(1, '.');
// 		    }
// 		    curr.push_back(temp);
// 	    }
        
//         vector<vector<string>>ans;
//         int index=0;
        
//         ans = helper(ans, n, index, curr);
        
//         return ans.size();
//     }
// };