// TC -> O(Log(N) + Log(M))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = -1;
        
        int low = 0;
        int high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1])
            {
                row = mid;
                break;
            }
            
            if(target < matrix[mid][m-1])
                high = mid-1;
            else
                low = mid+1;
        }
        
        if(row == -1)
            return false;
        
        low = 0;
        high = m-1;
        
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