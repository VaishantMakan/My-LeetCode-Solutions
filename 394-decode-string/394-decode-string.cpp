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
        
        // if no number , then it can either be ] or some char
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
        
        // since last element was a num, hence curr element will be [
        index++;    // to skip [
        
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
        
        index++; // to skip the last element i.e ] 
        
        string temp = ans; // this will get repeated num times 
        
        while(num-- != 1)  // since already added once before 
        {
            ans += temp;
        }
        
        if(index < s.length() && s[index] != ']') // if after ] there is still some char or num
        {   
            ans += helper(s, index);
        }
        
        // now the curr index element is ] , so we just return 
        return ans;
    }
    
    string decodeString(string s) {
        
        int index=0;
        
        return helper(s, index);
    }
};