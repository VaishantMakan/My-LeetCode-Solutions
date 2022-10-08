// Intuition -> when k is 2 , then basically we can do => Buy, Sell, Buy, Sell , hence 4 moves 
// and we can see that we buy only on even moves, hence we can eliminate buy variable and calculate using k
// similarly for k = 3 => B, S, B, S, B, S , hence 6 moves ....

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>>dp(n+1, vector<int>(k*2+1, 0));
        
        for(int day = n-1; day>=0; day--)
        {
            for(int transactionsLeft = k*2-1; transactionsLeft >= 0; transactionsLeft--)
            {
                //no transaction
                int ans1 = dp[day+1][transactionsLeft];

                //transaction
                int ans2=0;

                bool buy = (transactionsLeft % 2 == 0);

                if(buy)
                {
                    ans2 = -prices[day] + dp[day+1][transactionsLeft+1];
                }
                else
                {
                    ans2 = prices[day] + dp[day+1][transactionsLeft+1];
                }

                dp[day][transactionsLeft] = max(ans1, ans2);
            }
        }
        
        return dp[0][0];
    }
};