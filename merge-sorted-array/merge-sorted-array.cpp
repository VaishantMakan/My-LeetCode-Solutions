class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int temp[m+n];
        int i=0;
        int l=0,h=0;
        while(l<m && h<n)
        {
            if(nums1[l]<nums2[h])
            {
                temp[i++]=nums1[l];
                l++;
            }
            else
            {
                temp[i++]=nums2[h];
                h++;
            }
        }
        
        while(l<m)
        {
            temp[i++]=nums1[l++];
        }
        
        while(h<n)
        {
            temp[i++]=nums2[h++];
        }
        
        for(int i=0;i<n+m;i++)
        {
            nums1[i]=temp[i];
        }
    }
};