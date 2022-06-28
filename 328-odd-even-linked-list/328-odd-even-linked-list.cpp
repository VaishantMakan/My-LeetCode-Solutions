/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL)
            return head;
        
        int numOfOdds = 1;
        
        ListNode* temp = head;
        
        while(temp->next != NULL && temp->next->next != NULL)
        {
            numOfOdds++;
            
            temp = temp->next->next;
        }
        
        int n=1;
        
        ListNode* tail = head;
        
        while(tail->next != NULL)
        {
            n++;
            tail = tail->next;
        }
        // cout<<n<<endl;
        int count=0;
        
        temp = head;
        
        int check;
        
        if(n%2 == 0 && n!=2)
            check = numOfOdds;
        else
            check = numOfOdds-1;
        
        while(count != check)
        {
            count++;
            
            ListNode* nextOdd = temp->next->next;
            
            tail->next = temp->next;
            temp->next->next = NULL;
            tail = tail->next;
            
            temp->next = nextOdd;
            
            temp = temp->next;
            
        }
        
        return head;
    }
};