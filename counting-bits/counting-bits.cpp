class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>mem(n+1,0);
        mem[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            mem[i] = (mem[i/2]) + i%2;
        }
        
        return mem;
    }
};

//Explanation : If number i is even then it will have the same number of 1's bits as the number i/2 . If its odd then it will have 1 + num of 1's bits in i/2 
