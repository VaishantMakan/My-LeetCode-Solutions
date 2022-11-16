class Solution {
public:
    
    vector<vector<string>>ans;
    vector<string>temp;
    
    bool isPalindrome(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void helper(string& s, int i, int n)
    {
        if(i >= n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(s, i, j))
            {
                temp.push_back(s.substr(i, j-i+1));
                helper(s, j+1, n);
                temp.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        
        helper(s, 0, n);
        
        return ans;
    }
};