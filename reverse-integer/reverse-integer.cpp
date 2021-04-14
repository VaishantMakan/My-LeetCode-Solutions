class Solution {
public:
    int reverse(int x) {
        
        long long ans=0;
        int count=0;
        int sign = 0;
        
        if(x > 0)
            sign=1;
        else
            sign=-1;
        
        int temp = abs(x);
        
        while(temp > 0)
        {
            temp /= 10;
            count++;
        }
        
        count--;
        
        x=abs(x);
        
        while(x > 0)
        {
            ans += ((x%10)*(pow(10,count)));
            x /= 10;
            count--;
        }
        
        if(sign < 0)
        {
            ans *= -1;
        }
        
        int leftRange = pow(-2,31);
        int rightRange= pow(2,31)-1;
        
        if(ans < leftRange || ans > rightRange )
            return 0;
        
        return int(ans);
    }
};