/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==nullptr)
            return false;
        
        ListNode* turtle=head;
        ListNode* rabbit=head;
        bool ans = false;
        
        while(rabbit->next != nullptr && rabbit->next->next != nullptr)
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            
            if(turtle == rabbit)
            {
                ans=true;
                break;
            }
        }
        return ans;
    }
};