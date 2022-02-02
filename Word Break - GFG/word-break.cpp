// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool helper(const string& s, int start, const unordered_set<string>& d, vector<int>& dp) {
        
        if (start == s.size()) {
            return true;
        }
        
        if (dp[start] != -1) 
            return dp[start];
        
        for (int i = start; i < s.size(); ++i) 
        {
            const string sub = s.substr(start, i - start + 1); 
            if (d.count(sub) == 1) 
            {
                if (helper(s, i+1, d, dp)) {
                    dp[start] = 1;
                    return true;
                }
            }
        }
        
        dp[start] = 0;
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        
        unordered_set<string> d(B.begin(), B.end());
		
        // Use a vector since we can index from 0 to N. 
		// Possible values in vector are: -1, 0, 1.
        vector<int> dp(A.length(), -1); 
        return helper(A, 0, d, dp);  
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends