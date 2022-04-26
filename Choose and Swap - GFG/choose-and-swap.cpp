// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        vector<int> charA(26,-1);
        
        int n=a.length();
        
        // To store the first index of
        // every character of str
        
        for(int i=0;i<n;i++)
        {
            // If current character is appearing
            // for the first time in str
            if(charA[a[i] - 'a'] == -1)
            {
                charA[a[i] - 'a'] = i;
            }
        }
        
        int k,m;
        
        for(k=0;k<n;k++)
        {
            bool flag = false;
            
            for(m=0; m< (a[k]-'a') ; m++)
            {
                // If there is a character in str which is
                // smaller than str[i] and appears after it
                if(charA[m] > charA[a[k]-'a'])
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag)
                break;
        }
        
        if(k < n)
        {
            char c1 = a[k];
            char c2 = char(m + 'a');
            
            for(int i=0;i<n;i++)
            {
                if(a[i]==c1)
                    a[i]=c2;
                
                else if(a[i]==c2)
                    a[i]=c1;
            }
        }
        
        return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends