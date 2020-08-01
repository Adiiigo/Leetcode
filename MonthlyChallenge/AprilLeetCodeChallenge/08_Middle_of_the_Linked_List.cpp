Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

Note:

    The number of nodes in the given list will be between 1 and 100.

Solutions:
- using two pointers

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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *one_step = head ;
        ListNode *two_step = head ;
        
        while(two_step->next != NULL && two_step->next->next != NULL){
            one_step = one_step->next ;
            two_step = two_step->next->next ;
        }
 
        if(two_step->next != NULL){
            one_step = one_step->next ;
        }
        
        return one_step;
        
    }
};

Time Complexity - O(n/2) - because we are taking to jumps at a time and coming to the solution
Space Complexity - O(1) - no extra space is used
