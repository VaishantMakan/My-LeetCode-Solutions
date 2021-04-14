class Solution {
public:
    int reverse(int x) {
        
        int rev=0;
        
        while(x!=0)
        {
            int num = x%10;
            x /= 10;
            
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && num > 7)) 
                return 0;
            
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && num < -8)) 
                return 0;
            
            // INT_MAX = 2147483647 ..... INT_MAX/10 = 214748364 ... remainder = 7
            // INT_MIN = -2147483648 ..... INT_MIN/10 = -214748364 ... remainder = 8
            
            rev = rev * 10 + num;
        }
        return rev;
    }
};