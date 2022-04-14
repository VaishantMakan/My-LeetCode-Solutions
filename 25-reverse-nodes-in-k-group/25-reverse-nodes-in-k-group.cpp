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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prevHead = NULL;
        ListNode* newHead = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        
        int itr = count/k;
        
        while(itr--)
        {
            int index=1;
            prev = NULL;
            
            while(index <= k)
            {
                if(curr == NULL)
                    break;
                    
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                
                index++;
            }
            
            if(newHead == head)
                newHead = prev;
                
            if(prevHead == NULL)
                prevHead = head;
            else
            {
                prevHead->next = prev;
                prevHead = head;
            }
            
            head = curr;
        }
        
        prevHead->next = head;
        
        return newHead;
    }
};