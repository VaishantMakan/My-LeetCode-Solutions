// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
    Node* merge(Node* head1, Node* head2)
    {
        Node* temp = new Node(-1);
        Node* finalHead = temp;
        
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->data < head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            
            temp = temp->next;
        }
        
        while(head1 != NULL)
        {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        
        while(head2 != NULL)
        {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        
        return finalHead->next;
    }
  
    Node* middle(Node* head)
    {
        Node* slow = head, *fast = head->next; // this way we get the middle element in slow and it also works when only 2 elements present in the list 
        
        while(slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* mid = middle(head);
        Node* head2 = mid->next;
        mid->next = NULL;
        
        head = mergeSort(head);
        head2 = mergeSort(head2);
        Node* finalHead = merge(head, head2);
        
        return finalHead;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends