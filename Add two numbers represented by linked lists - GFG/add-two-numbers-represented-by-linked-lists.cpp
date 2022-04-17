// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL , *next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        Node* newHead = NULL;
        Node* newTemp = NULL;
        
        int carry = 0;
        
        while(first != NULL && second != NULL)
        {
            int newVal = first->data + second->data + carry;
            
            if(newVal > 9)
            {
                newVal = newVal%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            Node* newNode = new Node(newVal);
            
            if(newHead == NULL)
            {
                newHead = newNode;
                newTemp = newNode;
            }
            else
            {
                newTemp->next = newNode;
                newTemp = newTemp->next;
            }
            
            first = first->next;
            second = second->next;
        }
        
        while(first != NULL)
        {
            int newVal = first->data + carry;
            
            if(newVal > 9)
            {
                newVal = 0;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            Node* newNode = new Node(newVal);
            
            newTemp->next = newNode;
            newTemp = newTemp->next;
            
            first = first->next;
        }
        
        while(second != NULL)
        {
            int newVal = second->data + carry;
            
            if(newVal > 9)
            {
                newVal = 0;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            Node* newNode = new Node(newVal);
            
            newTemp->next = newNode;
            newTemp = newTemp->next;
            
            second = second->next;
        }
        
        if(carry == 1)
        {
            Node* newNode = new Node(1);
            newTemp->next = newNode;
            newTemp = newTemp->next;
        }
        
        newHead = reverse(newHead);
        return newHead;
    }
};







// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends