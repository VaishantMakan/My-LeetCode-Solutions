// O(N) Solution : https://abhinandandubey.github.io/posts/2019/12/15/Largest-Rectangle-In-Histogram.html
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int res = 0, curr = 0, n = heights.size();
        
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(s.empty() == false && heights[s.top()]>=heights[i] )
            {
                int top = s.top();
                s.pop();
                if(s.empty())
                    curr = heights[top]*i;
                else
                    curr = heights[top]*(i-s.top()-1);
                res = max(curr,res);
            }
            
            s.push(i);
        }
        
        //For the elements left in the stack
        while(s.empty() == false){
                int top = s.top();
                s.pop();
                if(s.empty())
                    curr = heights[top]*n;
                else
                    curr = heights[top]*(n-s.top()-1);
                res = max(curr,res);
            }
        return res;
    }
};


// O(N^2) Solution : 

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
        
//         int n = heights.size();
//         int ans = INT_MIN;
//         for(int i=0;i<n;i++)
//         {
//             int curr = heights[i];
//             int left=0;
//             //check left 
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(heights[j] >= curr)
//                     left++;
//                 else
//                     break;
//             }
            
//             int right=0;
//             //check right
//             for(int j=i+1;j<n;j++)
//             {
//                 if(heights[j] >= curr)
//                     right++;
//                 else
//                     break;
//             }
            
            
//             //calc area 
//             ans = max(ans, (left+right+1)*curr);
//         }
//         return ans;
//     }
// };