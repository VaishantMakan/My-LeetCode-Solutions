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
    
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* temp = new ListNode(-1);
        ListNode* finalHead = temp;
        
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val < head2->val)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            
            temp = temp->next;
        }
        
        while(head1 != NULL)
        {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        
        while(head2 != NULL)
        {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        
        return finalHead->next;
    }
  
    ListNode* middle(ListNode* head)
    {
        ListNode* slow = head, *fast = head->next; // this way we get the middle element in slow and it also works when only 2 elements present in the list 
        
        while(slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
  
    //Function to sort the given linked list using Merge Sort.
    ListNode* mergeSort(ListNode* head) {
        // your code here
        
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* mid = middle(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        
        head = mergeSort(head);
        head2 = mergeSort(head2);
        ListNode* finalHead = merge(head, head2);
        
        return finalHead;
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};