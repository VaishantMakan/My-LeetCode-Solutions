class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        //cyclic sort
        
        int i=0;
        while(i<arr.size())
        {
            if(arr[i] > 0 && arr[i] <= arr.size() && arr[i] != i+1)
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
            else
                i++;
        }
        
        int count=0;
        int ans;
        
        unordered_set<int>s;
        
        for(int i=0; i<arr.size() && count < k; i++)
        {
            if(arr[i] != i+1)
            {
                count++;
                ans = i+1;
                s.insert(arr[i]);
            }
        }
        
        //extra numbers 
        for(int i=1; count<k; i++)
        {
            int temp = arr.size() + i;
            
            if(s.find(temp) == s.end())
            {
                ans = temp;
                count++;
            }
        }
        
        return ans;
    }
};