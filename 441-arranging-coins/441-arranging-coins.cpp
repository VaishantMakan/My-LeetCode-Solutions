class Solution {
public:
    int arrangeCoins(int n) {
        if(n<2)
            return n;
        if(n==2)
            return 1;
        if(n<6)
            return 2;
        int start=1,end=n/2;
        while(start<=end)
        {
            long x=start+(end-start)/2;
            long sum = x * (x + 1) / 2 ;
            // System.out.println(x+"  "+sum);
            if(sum == n){
                return x;
            }
                
            if(sum<n)
            {
                start=x+1;
            }
            else
            {
                end=x-1;
            }
        }
        return end;
    }
};