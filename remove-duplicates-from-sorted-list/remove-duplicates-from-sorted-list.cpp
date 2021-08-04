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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(temp==head && temp->next != nullptr && temp->val == temp->next->val)
            {
                head = temp->next;
                temp=temp->next;
                continue;
            }
            else if(temp->next != nullptr && temp->next->next != nullptr && temp->next->next->val == temp->next->val)
            {
                temp->next = temp->next->next;
                continue;
            }
            else
            {
                temp=temp->next;
            }
        }
        return head;
    }
};