class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> ans;
        
        int n = size(arr);
        
        // gives the index of the element just greater than equal to x 
        int R = lower_bound(begin(arr), end(arr), x) - begin(arr); 

        int L = R - 1; // this will be the element just smaller than x 
            
        // now we have a possible window of the elemenst closest to x and 
        // now one by one we will add elements into this window by checking 
        // or you can say that these L and R are the pointers and we will check them and put acc. 
        
	    // expand the (L, R) window till the no. of elements between it are equal to k
        // This window's starting and ending points are not included yet, its just like the 
        // range, the elements that come in between it are to be included. 
            
        while(k--) 
        {
            if(R >= n || (L >= 0 && x - arr[L] <= arr[R] - x)) 
                L--;  // expand from left meaning that the current Left element comes inside the window and the left boundary expands 
            else 
                R++;  // expand from right meaning that teh current right element comes inside the window and the right boundary expands
        }
        
        // now add the elements inside the boundary 
        for(int i=L+1; i<R; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;  
    }
};