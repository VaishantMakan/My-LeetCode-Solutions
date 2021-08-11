class Solution {
public:
    
    int helper(int m, int n, int x, int y, int** dp, vector<vector<int>>& obstacleGrid)
    {
        if(x==m-1 && y==n-1)
            return 1;
        
        if(x<0 || x>=m || y<0 || y>=n || obstacleGrid[x][y]==1)
            return 0;
        
        if(dp[x][y] != -1)
            return dp[x][y];
        
        int temp1 = helper(m,n,x+1,y,dp,obstacleGrid);
        int temp2 = helper(m,n,x,y+1,dp,obstacleGrid);
        
        dp[x][y]=temp1+temp2;
        
        return temp1+temp2;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        int **dp = new int*[m];
        for(int i=0;i<m;i++)
            dp[i] = new int[n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
            
        
        return helper(m,n,0,0,dp,obstacleGrid);
    }
};