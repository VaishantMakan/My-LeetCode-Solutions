class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        // cout<<n<<" "<<m<<endl;
        
        int ir=0;
        int ic=m-1;
        
        int jr=0;
        int jc=m-1;
        
        vector<vector<int>>ans;
        
        while(1)
        {
            // swap(mat[ir][ic], mat[jr][jc]);
            
            vector<int>tempArr;
            
            int tempr = ir;
            int tempc = ic;
            
            // cout<<tempr<<" "<<tempc<<" "<<jr<<" "<<jc<<endl;
            
            while(tempr <= jr && tempc <= jc)
            {
                // cout<<tempr<<" "<<tempc<<" "<<jr<<" "<<jc<<endl;
                tempArr.push_back(mat[tempr][tempc]);
                tempr++;
                tempc++;
            }
            
            
            
            ans.push_back(tempArr);
            
            ic--;
            jr++;
            
            // if(jr == 3)
            //     cout<<"hrl"<<endl;
            
            if(ic < 0)
            {
                ic = 0;
                ir++;
            }
            
            if(ir >= n)
                break;
            
            if(jr >= n)
            {
                // cout<<"yo"<<endl;
                jr = n-1;
                jc--;
            }
            
            if(jc < 0)
                break;
            
        }
        
        for(int i=0; i<ans.size(); i++)
        {
            sort(ans[i].begin(), ans[i].end());
        }
        
        int indexr=0;
        
        ir=0;
        ic=m-1;
        
        jr=0;
        jc=m-1;
        
        while(1)
        {
            // swap(mat[ir][ic], mat[jr][jc]);
            
            // vector<int>tempArr;
            
            int tempr = ir;
            int tempc = ic;
            
            // cout<<tempr<<" "<<tempc<<" "<<jr<<" "<<jc<<endl;
            
            
            int indexc=0;
            
            while(tempr <= jr && tempc <= jc)
            {
                // cout<<tempr<<" "<<tempc<<" "<<jr<<" "<<jc<<endl;
                // tempArr.push_back(mat[tempr][tempc]);
                
                mat[tempr][tempc] = ans[indexr][indexc];
                
                tempr++;
                tempc++;
                
                indexc++;
            }
            
            
            
            // ans.push_back(tempArr);
            
            ic--;
            jr++;
            
            // if(jr == 3)
            //     cout<<"hrl"<<endl;
            
            if(ic < 0)
            {
                ic = 0;
                ir++;
            }
            
            if(ir >= n)
                break;
            
            if(jr >= n)
            {
                // cout<<"yo"<<endl;
                jr = n-1;
                jc--;
            }
            
            if(jc < 0)
                break;
            
            indexr++;
            
        }
        
    
//         for(int i=m-1; i; i++)
//         {
//             for(int j=0;j<m; j++)
//             {
                
//             }
//         }

        return mat;
        
    }
};