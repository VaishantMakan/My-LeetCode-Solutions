class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int currP=nums[0], currN=nums[0], res=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] < 0)
            {
                swap(currP, currN);
            }
            
            currP = max(nums[i], currP*nums[i]);
            currN = min(nums[i], currN*nums[i]);
            
            res = max(res, currP);
           
        }
        
        return res;
    }
}; 