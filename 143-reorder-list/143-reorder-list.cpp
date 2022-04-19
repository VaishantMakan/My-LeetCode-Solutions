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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL, * next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return;
        
        //find middle element 
        ListNode* prev = NULL;
        ListNode*slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
       
        // dividing the list into two
        prev->next = NULL;
        
        // now we will reverse the list from middle till last element
        ListNode* newHead = reverse(slow);
        
        // now we merge acc to question 
        
        ListNode* tempH = head, *nextH;
        
        ListNode* prevH = NULL;
        
        while(tempH != NULL && newHead != NULL)
        {   
            nextH = tempH->next;
            tempH->next = newHead;
            
            // for case when 2nd list is greater than 1st list that is when length of total list is odd
            prev = newHead;
            
            newHead = newHead->next;
            tempH->next->next = nextH;
            tempH = nextH;
        }
       
        while(newHead != NULL)
        {
            prev->next = newHead;
            prev = prev->next;
            
            newHead = newHead->next;
        }
        
    }
};