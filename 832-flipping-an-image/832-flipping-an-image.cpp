class Solution {
public:
    
    // The basic idea is for flipping a row horizontally we will just reverse the array 
    // and for inverting an image we wll just do 1's compliment for each element in that row and it will be done by taking its xor with 1 
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n = image.size();
        for(int i=0;i<n;i++)
        {
            reverse(image[i].begin(), image[i].end());
            for(int j=0;j<image[i].size();j++)
            {
                image[i][j] ^= 1;
            }
        }
        
        return image;
    }
};