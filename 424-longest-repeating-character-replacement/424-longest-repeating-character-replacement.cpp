class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        
        unordered_map<char,int> m; // this will store the curr frequency of char in our window
        
        int i=0; // the starting pointer of the possible ans string 
        int j=0; // the ending pointer of the possible ans string
        
        int maxi=0; // it tells the count of the element that came maximum times in the possible ans string 
        
        int ans=0; // this will store the final ans
        
        // note that j-i+1 will give us the length of our possible string that we have chosen with i and j 
        
        // j-i+1-maxi will tell us about the count of elements 
        // that we would change to get the max ans i.e j-1+1 
        // as maxi has the most repeating elements no. and when we subtract from total length, the 
        // remaining number tells us about the elements that are not that maxi element
        // so if this quantity is greater than k, that means that we are changing more than k elements
        // so we remove the first element from our string & move the window ahead by one 
        
        while(j < n)
        {
            int tempLen = j-i+1;
            
            m[s[j]]++;
            
            maxi = max(maxi, m[s[j]]);
            
            if(tempLen - maxi > k)
            {
                m[s[i]]--;
                i++;     //sliding the window by one 
            }
            
            // since the temp len could have been changed after the above if condition 
            tempLen = j-i+1;
            
            ans = max(ans, tempLen);
            
            j++;
        }
        
        return ans;
    }
};