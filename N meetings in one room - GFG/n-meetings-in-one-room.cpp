// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {   
            pair<int,int>p;
            p.first = start[i];
            p.second = end[i];
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), comp);
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        
        int ans=0;
        // starting=v[0].first;
        int ending=-1;
        
        for(int i=0;i<n;i++)
        {
            int starting=v[i].first;
            if(starting > ending)
            {
                ans++;
                ending=v[i].second;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends