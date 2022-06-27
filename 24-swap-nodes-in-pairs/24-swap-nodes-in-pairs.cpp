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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* curr = head;
        ListNode* prevNode = dummy;
        
        while(curr != NULL && curr->next != NULL)
        {
            ListNode* nextCurr = curr->next->next;
                
            prevNode->next = curr->next;
            
            prevNode = curr;
            
            curr->next->next = curr;
            
            curr->next = nextCurr;
            
            curr = nextCurr;    
        }
        
        return dummy->next;
    }
};