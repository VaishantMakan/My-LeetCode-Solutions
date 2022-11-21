class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        //concept : next smaller element 
        
        int n = prices.size();
        
        stack<int>s;
        
        vector<int>ans(n);
        
        for(int i=0;i<n;i++)
        {
            // if(s.empty() || prices[st.top()] < prices[i])
            // {
            //     s.push(i);
            // }
            
            ans[i] = prices[i];
            
            while(!s.empty() && prices[s.top()] >= prices[i])
            {
                ans[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            
            s.push(i);
        }
        
        return ans;
    }
};