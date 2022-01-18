class Solution {
public:
    
    void helper(vector<string>& ans, string digits, int index, string curr, string mapping[]) {
        
        //base condition 
        if(index >= digits.length())
        {
            ans.push_back(curr);
            return;
        }
        
        int num = digits[index] - '0';
        
        string letters = mapping[num];
        
        for(int i=0;i<letters.length();i++)
        {
            curr.push_back(letters[i]);
            helper(ans, digits, index+1, curr, mapping);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        
        if(digits.length() == 0)
            return ans;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        int index=0;
        
        string curr;
        
        helper(ans, digits, index, curr, mapping);
        
        return ans;
    }
};