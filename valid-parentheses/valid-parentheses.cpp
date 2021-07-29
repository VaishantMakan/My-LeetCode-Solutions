class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        
        stack<char> st;
        
        if(n==1)
            return false;
        
        if(n<1)
            return false;
        
        if(n%2!=0)
            return false;
        
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            
            if(c=='(' || c=='[' || c=='{')
            {
                st.push(c);
                continue;
            }
            
            if(c==')')
            {
                if(st.empty())
                    return false;
                
                if(st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            
            if(c==']')
            {
                if(st.empty())
                    return false;
                
                if(st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            
            if(c=='}')
            {
                if(st.empty())
                    return false;
                
                if(st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            
            st.push(c);
            
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};