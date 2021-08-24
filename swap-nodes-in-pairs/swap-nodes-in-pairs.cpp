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

// eg : [1,2,3]

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return head;
        
        // newHead = 2
        ListNode* newHead = head->next;
        
        // nextSequence = 3
        ListNode* nextSequence = head->next->next;
        
        // 2 -> 1
        newHead->next = head;
        
        head->next = swapPairs(nextSequence);
        
        return newHead;
    }
};