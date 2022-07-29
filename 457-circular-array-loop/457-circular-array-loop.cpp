class Solution {
public:
    
    int findNextElement(vector<int>& nums, int curr, bool isForward)
    {
        bool direction = nums[curr] >= 0;
        
        if(direction != isForward)
            return -1;
        
        int next = (nums[curr] + curr) % int(nums.size());
        
        if(next < 0)
            next = next + nums.size();
        
        if(next == curr)
            return -1;
        
        return next;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            int slow = i;
            int fast = i;
            
            bool isForward = nums[i] >= 0;
            
            //finding cycle 
            do{
                
                slow = findNextElement(nums, slow, isForward);
                
                fast = findNextElement(nums, fast, isForward);
                
                if(fast != -1)
                    fast = findNextElement(nums, fast, isForward);
                
            } while(slow != -1 && fast != -1 && slow != fast);
            
            if(slow != -1 && slow == fast)
                return true;
        }
        
        return false;
    }
};