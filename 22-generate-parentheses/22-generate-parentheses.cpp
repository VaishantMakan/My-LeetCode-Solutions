class Solution {
public:
    
    void helper(vector<string>& ans, int n, int m, string temp)
    {
        if(n == 0)
        {
            while(m--)
            {
                temp.push_back(')');
            }
            
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('(');
        helper(ans, n-1, m+1, temp);
        temp.pop_back();
        
        if(m >= 1)
        {
            temp.push_back(')');
            helper(ans, n, m-1, temp);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        
        int m = 1;
        
        string temp = "(";
        
        helper(ans, n-1, m, temp);
        
        return ans;
    }
};