class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //check all columns for this row
                int row = i;
                int col = j;
                
                bool check = true;
                for(int k=0;k<n;k++)
                {
                    if(grid[row][k] != grid[k][col])
                    {
                        check = false;
                        break;
                    }
                }
                
                if(check == true)
                    ans++;
            }
        }
        
        return ans;
    }
};