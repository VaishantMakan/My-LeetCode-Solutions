class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>v;
        int r=1;
        while(r<=numRows)
        {
            vector<int>temp;
            if(r==1)
            {
                temp.push_back(1);
                v.push_back(temp);
                r++;
                continue;
            }
            
            if(r==2)
            {
                temp.push_back(1);
                temp.push_back(1);
                v.push_back(temp);
                r++;
                continue;
            }
            for(int i=0;i<r;i++)
            {
                if(i==0 || i==r-1)
                {
                    temp.push_back(1);  
                    continue;
                }
                int ans=v[r-2][i-1]+v[r-2][i];
                temp.push_back(ans);
            }
            
            v.push_back(temp);
            r++;
        }
        return v;
    }
};