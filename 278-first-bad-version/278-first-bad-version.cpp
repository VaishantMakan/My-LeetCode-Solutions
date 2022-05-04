// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Binary Search
    int firstBadVersion(int n) {
        
        int minIndex=INT_MAX;
        int low=1;
        int high=n;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(isBadVersion(mid))
            {
                minIndex = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return minIndex;
    }
};