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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        int count=0;
        
        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        
        if(n==count)
        {
            head=head->next;
            return head;
        }
        
        temp = head;
        
        int flag=1;
        while(flag != count-n)
        {
            temp=temp->next;
            flag++;
        }
        
        temp->next=temp->next->next;
        return head;
    }
};