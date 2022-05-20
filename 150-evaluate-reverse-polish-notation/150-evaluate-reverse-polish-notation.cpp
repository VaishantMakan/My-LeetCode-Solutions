class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>s;
        
        int n = tokens.size();
        
        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                
                if(tokens[i] == "+")
                    s.push(n2+n1);
                
                if(tokens[i] == "-")
                    s.push(n2-n1);
                
                if(tokens[i] == "*")
                    s.push(n2*n1);
                
                if(tokens[i] == "/")
                    s.push(int(n2/n1));
            }
            else
                s.push(stoi(tokens[i]));
        }
        
        return s.top();
    }
};