class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)
            return false;
        
        if(n==1)
            return true;
        
        int temp = n%3;
        
        if(temp!=0)
            return false;
            
        return isPowerOfThree(n/3);
            
    }
};