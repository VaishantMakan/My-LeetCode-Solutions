// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    //custom sorting fuunction
    static bool comp(Item a, Item b)
    {
        double temp1 = double(a.value)/double(a.weight);
        double temp2 = double(b.value)/double(b.weight);
        
        return temp1 > temp2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        //sort the array in decreasing order of (value/weights) for each element
        sort(arr, arr+n, comp);
        
        int currW = 0;
        double currP=0.0;
        
        for(int i=0;i<n;i++)
        {
            if(currW + arr[i].weight <= W)
            {
                currW += arr[i].weight;
                currP += arr[i].value;
            }
            else {
                int remaining = W - currW;
                currP += (double(arr[i].value)/double(arr[i].weight))*remaining;
                break;
            }
        }
        
        return currP;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends