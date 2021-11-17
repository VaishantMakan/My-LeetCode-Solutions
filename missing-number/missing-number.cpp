// since it is given that we need to solve the question in O(n) time complexity and O(1) space complexity 
//and its also given that we have numbers from range 0-N , hence we'll apply cyclic sort ...

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        //sorting the array with cyclic sort modification
        int n=nums.size();
        int ans=n;
        int i=0;
        while(i<n)
        {
            //if number == N, then ignore it ...
            if(nums[i]==n)
            {
                i++;
                continue;
            }
            
            //correct index for each number is the number itself
            if(nums[i]==i)
            {
                i++;
                continue;
            }
            
            swap(nums[i], nums[nums[i]]);
        }
        
        //checking in the sorted array ...
        for(int i=0;i<n;i++)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        
        return ans;
    }
};