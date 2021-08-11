class Solution {
public:
    
    int helper(int m, int n, int x, int y, int** dp)
    {
        if(x==m-1 && y==n-1)
            return 1;
        
        if(x<0 || x>=m || y<0 || y>=n)
            return 0;
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        int temp1 = helper(m,n,x+1,y,dp);
        int temp2 = helper(m,n,x,y+1,dp);
        
        dp[x][y]=temp1+temp2;
        
        return temp1+temp2;
    }
    
    int uniquePaths(int m, int n) {
        
        int **dp = new int*[m];
        for(int i=0;i<m;i++)
            dp[i] = new int[n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
            
        
        return helper(m,n,0,0,dp);
    }
};