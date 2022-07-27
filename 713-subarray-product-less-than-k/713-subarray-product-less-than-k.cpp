class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 0)
            return 0;
        
        int n = nums.size();
        
        int count=0;
        int i=0;
        int prod=1;
        
        for(int e=0;e<n;e++)
        {
            prod *= nums[e];
            
            while(prod >= k && i <= e)
            {
                prod /= nums[i];
                i++;
            }
            
            count += e-i+1; // currently num of elements in our window
        }
        
        return count;
    }
};