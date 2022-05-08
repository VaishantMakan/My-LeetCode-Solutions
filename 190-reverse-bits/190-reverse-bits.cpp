// idea -> https://leetcode.com/problems/reverse-bits/discuss/54738/Sharing-my-2ms-Java-Solution-with-Explanation

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t m=0;
        
        for (int i = 0; i < 32; i++)
        {
            m = m<<1;
            
            if( (n & 1) == 1)
                m = m ^ 1;
            
            n = n>>1;
        }
        cout<<n<<endl;
        
        return m;
    }
};