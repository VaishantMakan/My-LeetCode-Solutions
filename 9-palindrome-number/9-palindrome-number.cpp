class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 || (x!=0 && x%10==0))  //this checks if given input is negative or inputs last digit is 0 or not 
            return false;             // bcuz any input with last digit 0 will be false for eg: 123210 
                                      // since 0123210 is not possible since 0 can never be in the front. 
        int sum=0;
        
        while(x > sum)
        {
            sum = sum*10 + x%10;   // this is baically building the number from back i.e reversing the number 
            x = x/10;              // until middle point crossed. 
        }
        
        return (x==sum) || (x == sum/10);  // x == sum/10 ... for when x is odd since middle element would be sum%10
    }
};