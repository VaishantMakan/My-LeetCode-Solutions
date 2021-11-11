class Solution {
public:
    int findPeakElement(vector<int>& a) {
        
         int n=a.size();
        int s=0;
        int e=n-1;
        
        int ans;
        
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            
            if(mid==0)
            {
                if((mid+1 <= n-1) && a[mid+1]<a[mid])
                    return mid;
                else
                    s=mid+1;
            }
            else if(mid-1 >=0 && a[mid-1] > a[mid])
            {
                //it means ans is on the left side
                e=mid-1;
            }
            else if(mid-1 >=0 && a[mid-1] < a[mid]  && mid+1 <= n-1 && a[mid+1] > a[mid])
            {
                //ans is on the right side
                s=mid+1;
            }
            else if(mid == n-1)
            {
                if(mid-1 >= 0 && a[mid]>a[mid-1])
                    return mid;
                else
                    e=mid-1;
            }
            else
            {
                ans = mid;
                return mid;
            }
        }
        return ans;
    }
};