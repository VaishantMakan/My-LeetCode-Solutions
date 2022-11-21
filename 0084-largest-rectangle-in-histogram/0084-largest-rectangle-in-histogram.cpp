//help: https://www.youtube.com/watch?v=X0X6G-eWgQ8

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        //to calculate area for a particular index, we need the following formula
        // (rightSmallIndex - leftSmallIndex) * heights[i]
        //where rightSmallIndex would give us the right boundary or the next lower element (nle) for the current index
        //similarly for the leftSmallIndex
                                
        vector<int>left(n, 0);
        vector<int>right(n, 0);                            
        
        stack<int>st;
      
        //for left
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
                left[i] = 0;
            else
            {
                left[i] = st.top() + 1;
            }
            
            st.push(i);
        }
        
        //empty the stack
        while(!st.empty())
            st.pop();
        
        //for right
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            if(st.empty())
                right[i] = n-1;
            else
                right[i] = st.top() - 1;
            
            st.push(i);
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, (right[i]-left[i]+1)*heights[i]);
        }
        
        return maxi;
    }
};