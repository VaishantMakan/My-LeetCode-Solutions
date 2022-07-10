class Solution {
public:
    
    static bool compare(string a, string b)
    {
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string>temp;
        
        for(auto it: nums)
            temp.push_back(to_string(it));
        
        sort(temp.begin(), temp.end(), compare);
        
        string ans = "";
        
        for(auto it: temp)
            ans += it;
        
        return ans[0] == '0' ? "0" : ans;
    }
};