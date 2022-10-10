class Solution {
public:
    
    char currLowestElement(vector<int>& freq)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i] != 0)
                return 'a' + i;
        }
        
        return 'z'; 
    
        // what this does is that when string s has been parsed i.e whole freq array is now 0 , but the stack is still not empty, meaning there
        //are still chars left, hence since z is the largest char, all leftover chars will be <= smallestCharPresentCurrentlyInS, hence they get
        //added up in the answer
    }
    
    string robotWithString(string s) {
        
        stack<int> t;
        
        string ans = "";
        
        vector<int>freq(26, 0);
        
        for(char c: s)
        {
            freq[c-'a']++;
        }
        
        for(char c: s)
        {
            t.push(c);
            freq[c-'a']--;
            
            char smallestCharPresentCurrentlyInS = currLowestElement(freq);
            
            while(!t.empty() && t.top() <= smallestCharPresentCurrentlyInS)
            {
                char x = t.top();
                t.pop();
                
                ans += x;
            }
        }
        
        return ans;
    }
};