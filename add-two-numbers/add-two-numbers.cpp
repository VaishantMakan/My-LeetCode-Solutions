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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = nullptr;
        
        int countL1 = 0;
        int countL2 = 0;
        
        ListNode* temp = l1;
        
        while(temp != nullptr)
        {
            countL1++;
            temp = temp->next;
        }
        
        temp = l2;
        
        while(temp != nullptr)
        {
            countL2++;
            temp = temp->next;
        }
        
        int count = min(countL1,countL2);
        
        int carry=0;
        
        //temp = head;
        
        while(count--)
        {
            int value = l1->val + l2->val + carry;
            
            ListNode* newNode = new ListNode();
            
            newNode->val= value%10;
            carry = value/10;
            
            if(head==nullptr)
            {
                head = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = newNode;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* currNode;
        count = abs(countL1 - countL2);
        
        if(countL1 > countL2)
            currNode = l1;
        else
            currNode = l2;
        
        while(count--)
        {
            int value = currNode->val + carry;
            
            ListNode* newNode = new ListNode();
            
            newNode->val = value%10;
            carry = value/10;
            
            temp->next = newNode;
            temp = newNode;
            
            currNode = currNode->next;
        }
        
        if(carry > 0)
        {
            ListNode* newNode = new ListNode();
            newNode->val = carry;
            carry=0;
            
            temp->next = newNode;
            temp = newNode;
        }
        
        return head;
    }
};