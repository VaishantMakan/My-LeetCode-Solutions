class Solution {
public:
    
    void helper(int num, int n, int k, vector<int>& ans)
    {
        if(n == 0)
        {
            ans.push_back(num);
            return;
        }
        
        int dig = num%10;
        
        if(dig + k <= 9)
        {
            helper(num*10+dig+k, n-1, k, ans);
        }
        
        if(k!=0 && dig-k >= 0) // k != 0 is used to avoid repetitions bcuz it would become same as the above case when k=0;
        {
            helper(num*10+dig-k, n-1, k, ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int>ans;
        
        for(int i=1;i<=9;i++)
        {
            helper(i, n-1, k, ans);
        }
        
        return ans;
    }
};