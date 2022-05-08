class Solution {
public:
    
    // using two pointer approach ,
    vector<int> sortedSquares(vector<int>& nums) {
        
        int firstPositiveNum = 0; 
        int n=nums.size();
        
        while(firstPositiveNum < n && nums[firstPositiveNum] < 0)
        {
            firstPositiveNum++;
        }
        
        // squaring all elements in array 
        for(auto &x: nums)
        {
            x *= x;
        }
        
        vector<int>result(n);
        int itr=0;
        
        // setting up two pointers
        int i= firstPositiveNum-1; // 1st pointer at the first negative num's square & will move left
        int j= firstPositiveNum;  // other pointer at the first positive num's square & will move right
    
        while(i >= 0 && j < n)
        {
            if(nums[i] < nums[j])
            {
                result[itr++] = nums[i--];
            }
            else
            {
                result[itr++] = nums[j++];
            }
        }
        
        // for leftover elements 
        while(i>=0)
            result[itr++] = nums[i--];
        
        while(j<n)
            result[itr++] = nums[j++];
        
        return result;
        
    }
};