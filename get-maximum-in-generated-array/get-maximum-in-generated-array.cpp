class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if (n == 0 || n == 1) 
            return n;
        
        vector<int>arr(n+1);
        arr[0] = 0;
        arr[1] = 1;
        int maximum = 1;
        
        for (int i = 2; i <= n; i++) 
        {
            //arr[i] = i % 2 != 0 ? arr[i / 2] + arr[i / 2 + 1] : arr[i/2]; 
            //to make it even faster we can write above line as below i.e use bit manipulation as /2 , so right shift by 1
            arr[i] = i & 1 ? arr[i >> 1] + arr[(i >> 1) + 1] : arr[i >> 1];
            maximum = max(maximum, arr[i]);
        }
        
        return maximum;
        
    }
};