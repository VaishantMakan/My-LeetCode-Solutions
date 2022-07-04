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
        
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL)
        {
            int val1 = l1->val;
            int val2 = l2->val;
            
            int add = val1 + val2 + carry;
            
            carry = add / 10;
            
            int finalVal = add % 10;
            
            ListNode* newNode = new ListNode(finalVal);
            temp->next = newNode;
            temp = temp->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            int val1 = l1->val;
            
            int add = val1 + carry;
            
            carry = add / 10;
            
            int finalVal = add % 10;
            
            ListNode* newNode = new ListNode(finalVal);
            temp->next = newNode;
            temp = temp->next;
            
            l1 = l1->next;
            
        }
        
         while(l2 != NULL)
        {
            int val1 = l2->val;
            
            int add = val1 + carry;
            
            carry = add / 10;
            
            int finalVal = add % 10;
            
            ListNode* newNode = new ListNode(finalVal);
            temp->next = newNode;
            temp = temp->next;
             
             l2 = l2->next;
            
        }
        
        if(carry)
        {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};