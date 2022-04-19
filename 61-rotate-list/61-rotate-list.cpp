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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        int n=1;
        
        // First make the linkedList Circular
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
            n++;
        }
        
        tail->next = head;
        
        // Now using two pointers we will find the newHead and uncircular the list 
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(k>n)
            k = k%n;
        
        while(k--)
            fast = fast->next;
        
        while(fast->next != head)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* newHead = slow->next;
        slow->next = NULL;
        
        return newHead;
    }
};