class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n=digits.size();
        while(1)
        {
            if(n==1 && digits[n-1]==9)
            {
                digits[n-1]=1;
                digits.push_back(0);
                return digits;
            }
            
            if(digits[n-1] == 9)
            {
                digits[n-1]=0;
                n--;
            }
            else
            {
                digits[n-1] = digits[n-1]+1;
                return digits;
            }
        }
    }
};