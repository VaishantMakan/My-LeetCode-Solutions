class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // now we know for the answer to exist, sum of gas >= sum of cost
        
        int sumGas = 0;
        int sumCost = 0;
        
        int n = gas.size();
        
        for(int i=0;i<n;i++)
        {
            sumGas += gas[i];
            sumCost += cost[i];
        }
        
        if(sumGas < sumCost)
            return -1;
        
        int ans = INT_MAX;
        int curr=0;
        
        // now since answer exists, hence there will be a index from which on starting we'll be able to reach till the end of the loop 
        
        for(int i=0;i<n;i++)
        {
            if(curr + gas[i]- cost[i] >= 0)
            {
                ans = min(i, ans);
                
                curr = curr + gas[i]- cost[i];
            }
            else
            {
                ans = INT_MAX;
                curr = 0;
            }
        }
        
        return ans;
    }
};