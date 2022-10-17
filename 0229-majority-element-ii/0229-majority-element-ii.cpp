// HELP TAKEN : https://www.youtube.com/watch?v=yDbkQd9t2ig&ab_channel=takeUforward

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans;
        
        int majEle1 = -1;
        int majEle2 = -1;
        
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == majEle1)
            {
                count1++;
            }
            else if(nums[i] == majEle2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                majEle1 = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                majEle2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        count1=0;
        count2=0;
        
        // checking majEle1 
        for(int i=0;i<n;i++)
        {
            if(nums[i] == majEle1)
                count1++;
        }
        
        if(count1 > n/3)
            ans.push_back(majEle1);
        
        //checking majEle2 
        
        if(majEle2 == majEle1)
            return ans;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == majEle2)
                count2++;
        }
        
        if(count2 > n/3)
            ans.push_back(majEle2);
        
        return ans;
    }
};