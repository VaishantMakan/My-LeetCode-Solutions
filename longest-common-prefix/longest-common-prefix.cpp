class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() ==0)
            return "";
        
        int n = strs.size();
        
        string ans ="";
        
        int min=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int temp = strs[i].length();
            if(temp < min)
            {
                min = temp;
            }
        }
        int count=0;
        
        for(int i=0;i<min;i++)
        {
            int flag=0;
            
            for(int j=1;j<n;j++)
            {
                if(strs[j][i] != strs[j-1][i])
                {
                    flag=1;
                    break;
                }
            }
            
            if(flag)
            {
                break;
            }
            
            count++;
        }
        
        if(count==0)
        {
            return ans;
        }
        
        ans += strs[0].substr(0,count);
        return ans;
    }
};