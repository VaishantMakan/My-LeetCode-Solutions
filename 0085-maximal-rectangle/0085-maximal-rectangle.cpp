//help : https://www.youtube.com/watch?v=tOylVCugy9k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=57

class Solution {
public:
    
    int largestRectangleArea(vector<int>& v)
    {
        int n = v.size();
        
        vector<int>left(n);
        vector<int>right(n);
        
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && v[st.top()] >= v[i])
            {
                st.pop();
            }
            
            if(st.empty())
                left[i] = 0;
            else
                left[i] = st.top() + 1;
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && v[st.top()] >= v[i])
            {
                st.pop();
            }
            
            if(st.empty())
                right[i] = n-1;
            else
                right[i] = st.top() - 1;
            
            st.push(i);
        }
        
        int maxi = 0;
        
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, (right[i]-left[i]+1)*v[i]);
        }
        
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxi=0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int>v(m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] - '0' == 1)
                    v[j]++;
                else
                    v[j] = 0;
            }
            
            maxi = max(maxi, largestRectangleArea(v));
        }
        
        return maxi;
    }
};