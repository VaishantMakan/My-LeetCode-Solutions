class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> mergedArray(nums1.size() + nums2.size());
        
        int i=0;
        int j=0;
        int k=0;
        
        while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] <= nums2[j]) {
            mergedArray[k] = nums1[i];
            i++;
        }
        else {
                mergedArray[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while (i < nums1.size()) {
            mergedArray[k] = nums1[i];
            i++;
            k++;
        }
        
        while (j < nums2.size()) {
            mergedArray[k] = nums2[j];
            j++;
            k++;
        }
        
        int n = mergedArray.size();
        
        if(n%2==0)
        {
            int mid = n/2;
            float f = float((mergedArray[mid-1]+mergedArray[mid]))/float(2);
            return f;     
        }
        else
        {
            int mid = ceil(n/2);
            return mergedArray[mid];
        }
        
    }
};