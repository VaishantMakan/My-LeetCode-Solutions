class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        int count=0;
        int temp = x;
        
        vector<int> v;
        
        while(temp > 0)
        {
            count++;
            int last = temp%10;
            v.push_back(last);
            temp=temp/10;
        }

        int start=0;
        int end=count-1;

        while(start < count)
        {
            if(v[start] != v[end])
            {
                return false;
            }

            start++;
            end--;
        }
        
        return true;
    }
};