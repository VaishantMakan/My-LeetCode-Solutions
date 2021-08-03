class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans;
        int carry=0;
        int n=a.length()-1, m=b.length()-1;
        
        while(n>=0 || m>=0)
        {
            int sum = carry;
            if(n>=0)
                sum += a[n--]-'0';
            
            if(m>=0)
                sum += b[m--]-'0';
            
            carry = sum>1 ? 1 : 0;
            ans += to_string(sum%2);
        }
        //if carry at last 
        if(carry)
            ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};