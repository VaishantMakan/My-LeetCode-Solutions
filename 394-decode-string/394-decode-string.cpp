class Solution {
public:
    
    static string helper(string s, int& index)
    {
        string ans = "";
        
        if(index >= s.length())
            return ans;
        
        int num = 0;
        
        while(s[index] - '0' >= 0 && s[index] - '0' <= 9)
        {   
            num = (num*10) + (s[index] - '0');
            
            index++;
        }
        
        // if no number 
        if(num == 0)
        {
            if(s[index] == ']')
            {
                return ans;
            }
            
            // its a char 
            ans += s[index];
            
            index++;
            
            ans += helper(s, index);
            return ans;
        }
        
        index++; // to skip [
        
        while(s[index] != ']')
        {   
            if(s[index] - '0' >= 0 && s[index] - '0' <= 9)
            {
                ans += helper(s, index);  
                
                continue;                
            }
            
            ans += s[index];
            
            index++;
        }
        
        index++;
        
        string temp = ans;
        
        while(num-- != 1)
        {
            ans += temp;
        }
        
        if(index < s.length() && s[index] != ']')
        {   
            ans += helper(s, index);
        }
        
        return ans;
    }
    
    string decodeString(string s) {
        
        int index=0;
        
        return helper(s, index);
    }
};