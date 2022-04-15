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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int index=1;
        ListNode* temp = head;
        ListNode* prevHead = head;
        
        while(index != left)
        {
            prevHead = temp;
            temp = temp->next;
            index++;
        }
        
        ListNode* curr = temp;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(index <= right)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            index++;
        }
        
        prevHead->next = prev;
        temp->next = curr;
        
        if(left == 1)
            return prev;
        
        return head;
    }
};