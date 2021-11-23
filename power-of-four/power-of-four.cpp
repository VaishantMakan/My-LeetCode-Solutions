class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
            return false;
        
        if(n==1)
            return true;
        
        int temp = n%4;
        
        if(temp!=0)
            return false;
            
        return isPowerOfFour(n/4);
        
    }
};