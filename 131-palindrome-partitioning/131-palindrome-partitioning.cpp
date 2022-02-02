class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string> v;
    
    bool checkPalindrome(string &str, int i, int j)
    {
        while(i<=j)
        {
            if(str[i++] != str[j--])
                return false;
        }
        return true;
    }
    
    void helper(string &str, int i, int j)
    {
        if(i>j)
        {
            ans.push_back(v);
            return;
        }
            
        for(int k=i;k<=j;k++)
        {
            if(checkPalindrome(str, i, k))
            {
                v.push_back(str.substr(i,k-i+1));
                helper(str, k+1, j);
                v.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> palindromicPartition(string str)
    {
        int n=str.size();
        
        helper(str, 0, n-1);
        return ans;
    }
    
    vector<vector<string>> partition(string s) {
        
        return palindromicPartition(s);
    }
};