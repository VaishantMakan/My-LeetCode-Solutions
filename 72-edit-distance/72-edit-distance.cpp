class Solution {
public:
    int minDistance(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        int dp[n+1][m+1];
        
        // if string2 is empty then min distance would be to delete all elements in string1 , hence ans would be the num of elements in string1. 
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = i;
        }
        // similarly, if string1 was empty then delete all elements in string2 for min ans
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = j;
        }
        
        //suppose text1 = horse and text2 = ros , then 
        //Meaning of this dp[3][2] is that when i am at text1[2] and text2[1] elements then what is the ans , i.e when text1 = hor and text2 = ro , 
        //then what is the ans .... so we check from their last elements and it derives the final ans by checking the elements before them . 
        //now when a char in string1 matches in string2, you don't need to do anything , just check the previous elements of both strings for dist.
        //but if the two elements are diff then, you have 3 options : Insert , Replace , Delete 
        // if you insert , then i remains same as you must have added an element before it so we are still checking the curr element but j would become j-1 as we 
        //would have inserted this jth element only , so dp[i][j-1]
        //if we replace , then that means we are replacing the ith element with jth element , so we move both the pointers to the next element, i.e i-1, j-1
        //so dp[i-1][j-1]
        //if we delete , then it means we are simply deleting the ith element that is simply move to the next ith element, so dp[i-1][j]
        //and finally the answer will be 1 + min (Insert, Replace, Delete)
        // see strivers video for better explanation ......

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //if elements equal 
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i][j-1] , min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
        }
        
        return dp[n][m];
    }
};