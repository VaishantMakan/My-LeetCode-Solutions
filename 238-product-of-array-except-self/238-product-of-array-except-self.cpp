class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // O(N) & O(1) space
        
        int n = nums.size();
        
        vector<int>ans(n, 1);
        
        //calculating prefix sum 
        for(int i=1;i<n;i++)
        {
            ans[i] = ans[i-1]*nums[i-1];
        }
        
        //calculating suffix sum
        int suffixP = 1;
        for(int i = n-1; i>=0; i--)
        {
            ans[i] *= suffixP;
            suffixP *= nums[i];
        }
        
        return ans;
    }
    
};