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
        
        if(head == NULL)
            return head;
        
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        
        bool isHead = true;
        
        int prevValue = -101;
        
        while(temp != NULL)
        {
            if(temp->next != NULL && temp->val == temp->next->val)
            {   
                ListNode* prev1 = temp;
                ListNode* prev2 = temp->next;
                temp = temp->next->next;
            
                prevValue = prev1->val;
                
                delete prev1;
                delete prev2;
                
                if(isHead == true)
                    head = temp;
                
                continue;
            }
            else if(temp->val == prevValue)
            {
                ListNode* flag = temp;
                temp = temp->next;
                delete flag;
                
                if(isHead == true)
                    head = temp;
                
                continue;
            }
            else
            {
                if(isHead == true)
                {
                    isHead = false;
                    prevNode = temp;
                    // prevNode->next = NULL;
                    temp = temp->next;
                }
                else
                {
                    prevNode->next = temp;
                    prevNode = temp;
                    temp = temp->next;
                }
            }
        }
        
        if(prevNode != NULL)
            prevNode->next = NULL;
        
        return head;
    }
};