class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0)
            return 0;
        
        int l=0, h=x, mid;
        int ans;
        
        while(l<=h)
        {
            mid=(l+h)/2;
            if(mid==0)
                return 1;
            
            if(mid == x/mid)
                return mid;
            
            else if(mid < x/mid)
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};