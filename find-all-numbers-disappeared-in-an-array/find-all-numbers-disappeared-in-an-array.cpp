class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        //If we were given a range and asked to do this ques in O(n) tc but any space complexity
        //Then we could have solved sing counting sort as shown below : 
        //return helperCountingSort(nums);
        
        //But Since we are given a range and asked to do this ques in O(n) tc and O(1) sc 
        //Then we can solve using cyclic sort as shown below : 
        return helperCyclicSort(nums);
        
    }
    
    vector<int> helperCountingSort(vector<int>& nums)
    {
        int n=nums.size();
        
        vector<int>a(n,0);
        
        for(int i=0;i<n;i++)
        {
            a[nums[i]-1]++;
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                ans.push_back(i+1);
        }
        
        return ans;
    }
    
    vector<int> helperCyclicSort(vector<int>& nums)
    {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
           if(nums[i] != i+1)
           {
               if(nums[i] != nums[nums[i]-1])
               {
                   swap(nums[i], nums[nums[i]-1]);
               }
               else
               {
                   //we just ignore it ...
                   i++;
                   continue;
               }
           }
           else
           {
               //already at correct position ...
               i++;
               continue;
           }
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};
