class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        
        vector<int>ans;
        
        if(x <= arr[0])
        {
            int j=0;
            while(k--)
            {
                ans.push_back(arr[j++]);        
            }
            return ans;
        }
        
        if(x >= arr[n-1])
        {
            int j=n-k;
            while(k--)
            {
                ans.push_back(arr[j++]);        
            }
            return ans;
        }
        
        int start = 0;
        int end = n-1;
        
        int count=0;
        
        while(start <= end)
        {
            if(end - start + 1 == k)
            {
               break;
            }
            
            int d1 = abs(arr[start] - x);
            int d2 = abs(arr[end] - x);
            
            if(d1 <= d2)
                end--;
            else
                start++;
        }
        
        for(int i=start;i<=end;i++)
            ans.push_back(arr[i]);
        
        return ans;
    }
};