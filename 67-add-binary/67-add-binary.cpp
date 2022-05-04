class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length() - 1;
        int m = b.length() - 1;
        
        string ans = "";
        bool carry = false;
        
        while(n >= 0 && m >= 0)
        {
            if(a[n] == '0' && b[m] == '0')
            {
                if(carry)
                {
                    ans += '1';
                    carry = false;
                }
                else {
                    ans += '0';
                }
            }
            else if(a[n] == '1' && b[m] == '1')
            {
                if(carry)
                {
                    ans += '1';
                    carry = true;
                }
                else {
                    ans += '0';
                    carry = true;
                }
            }
            else
            {
                if(carry)
                {
                    ans += '0';
                    carry = true;
                }
                else {
                    ans += '1';
                }
            }
            
            n--;
            m--;
        }
        
        while(n>=0)
        {
            if(carry)
            {
                if(a[n]=='1')
                {
                    ans += '0';
                    carry = true;
                }
                else
                {
                    ans += '1';
                    carry = false;
                }
            }
            else {
                ans += a[n];
            }
            
            n--;
        }
        
        while(m>=0)
        {
            if(carry)
            {
                if(b[m]=='1')
                {
                    ans += '0';
                    carry = true;
                }
                else
                {
                    ans += '1';
                    carry = false;
                }
            }
            else {
                ans += b[m];
            }
            
            m--;
        }
        
        if(carry)
            ans += '1';
    
        int i=0;
        int j=ans.length()-1;
    
        while(i <= j)
        {
            swap(ans[i++], ans[j--]);
        }
        
        return ans;
    }
};