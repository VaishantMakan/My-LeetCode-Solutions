class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> visited;
        
        int n = s.length();
        
        //max length
        int maxL = 0;
        
        //starting index 
        int i=0;
        
        //iterating over ending index
        for(int j=0;j<n;j++)
        {
            
            if(visited.find(s[j]) != visited.end())
            {
                i = max(i, visited[s[j]] + 1);
                // max because for eg : s = tmmzuxt , when we will reach last t element at 
                // that time our i will be at 2 index i.e 2nd m and visited[s[j]] + 1 would be 
                // 1 index i.e first m , hence in this case we would want i to remain at its 
                // previous pos only. 
                // this suggests that whenever visited[s[j]] is smaller than previous value of i 
                // then there is some element after visited[s[j]] + 1 index that is repeating 
                // hence for that reason only we take i as its previous pos only. 
                
                // because of this we do not need to manually remove all the elements that 
                // came before this repeating char in map 
            }
            
            visited[s[j]] = j;
            maxL = max(maxL, j - i + 1);
            
        }
        
        return maxL;
    }
};