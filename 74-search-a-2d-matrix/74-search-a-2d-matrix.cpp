class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = -1;
        
        for(int i=0; i<n; i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][m-1])
            {
                row = i;
                break;
            }
        }
        
        if(row == -1)
            return false;
        
        int low = 0;
        int high = m-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if(matrix[row][mid] == target)
                return true;
            
            if(target < matrix[row][mid])
                high = mid-1;
            else
                low = mid+1;
        }
        
        return false;
    }
};