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
    
    ListNode* middle(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL, *next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    int count(ListNode* head)
    {
        ListNode* temp = head;
        int c=0;
        
        while(temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return true;
        
        int n = count(head);
        
        ListNode* mid = middle(head);
        ListNode* newHead=NULL;
        
        if(n%2==0)
        {
            newHead = reverse(mid);
        }
        else
        { 
            newHead = reverse(mid->next);
        }
        
        while(head != NULL && head != mid || newHead != NULL && newHead->next != NULL)
        {
            if(head->val != newHead->val)
                return false;
            
            head = head->next;
            newHead = newHead->next;
        }
        
        return true;
    }
};