class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int nums = n*m;
        
        int sr = -1;
        int sc = -1;
        
        int er = n+1;
        int ec = m+1;
        
        vector<int>ans;
        
        while(nums)
        {
            sr++;
            sc++;
            
            er--;
            ec--;
            
            int cr = sr;
            int cc = sc;
            
            // right
            for(; cc<ec; cc++)
            {
                if(nums == 0)
                    break;
                
                ans.push_back(matrix[cr][cc]);
                nums--;
            }
            
            //down
            cr++;
            cc--;
            for(; cr<er; cr++)
            {
                if(nums == 0)
                    break;
                
                ans.push_back(matrix[cr][cc]);
                nums--;
            }
            
            //left
            cc--;
            cr--;
            for(; cc>=sc; cc--)
            {
                if(nums == 0)
                    break;
                
                ans.push_back(matrix[cr][cc]);
                nums--;
            }
            
            //up
            cr--;
            cc++;
            for(; cr>sr; cr--)
            {
                if(nums == 0)
                    break;
                
                ans.push_back(matrix[cr][cc]);
                nums--;
            }
            
            cr++;
        }
        return ans;
    }
};