class Solution {
public:
    
    void backtrack(vector<string> &output, string curr, int open, int close, int max)
    {
        if(curr.length() == 2*max)
        {
            output.push_back(curr);
            return;
        }
        
        if(open < max)
            backtrack(output, curr+"(", open+1, close, max);
        
        if(close < open)
            backtrack(output, curr+")", open, close+1, max);
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string>output;
        backtrack(output,"",0,0,n);
        return output;
    }
};