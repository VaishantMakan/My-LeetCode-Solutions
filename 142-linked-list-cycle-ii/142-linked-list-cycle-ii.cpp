/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*  Approach: Floyd's Cycle Detection
	
	STEP 1: Detect cycle using FCD
	STEP 2: Place one pointer at head of LL | Another pointer should be at the point where fast and slow meet
	STEP 3: Move 1st pointer and 2nd pointer by one step each 
	STEP 4: Both will meet again at entry point of cycle 
	
	Ex: 1->2->3->4->5
		      |     |
		      |-----|


				    slow
					 |	   (Both meet at 4)
					 ---------- fast
	STEP 1: 1->2->3->4->5  
		   	      |     |
		          |-----|
		       
		       
		       
		  slow   (Placing slow at head)
			|	     <--------- fast 				
	STEP 2: 1->2->3->4->5   
		   	      |     |
		          |-----|
		       
	STEP 3: Moving slow and fast by one step every time till they meet again
			 
	  slow     fast                        slow == fast     
	   |	    |    		                  |	     		
	1->2->3->4->5     =======>          1->2->3->4->5         ===========> both meet at 3 i.e. 3 is the entry point
		  |     |                             |     |
		  |-----|                             |-----|         
	
		       

*/



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) 
                break;
        }
        
        if (!(fast && fast->next)) 
            return NULL;
        
        while (head != slow) 
        {
            head = head->next;
            slow = slow->next;
        }
        
        return head;
    }
};