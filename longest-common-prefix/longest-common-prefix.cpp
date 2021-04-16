class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() ==0)
            return "";
        
        if(strs.size() ==1)
            return strs[0];
        
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
        
        sort(strs.begin(), strs.end());
        
        int count=0;
        
        for(int i=0;i<min;i++)
        {
            if(strs[0][i] != strs[n-1][i])
                break;
            
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