vector<int> dp(31,-1);

class Solution {
public:

    int fib(int n) {
        
        if(n<1)
            return 0;
        
        if(n==1 || n==2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = fib(n-1)+fib(n-2);
        
        return dp[n];
    }
};