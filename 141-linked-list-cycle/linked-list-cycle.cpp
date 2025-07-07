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
        ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next; // move slow by one node
        fast = fast->next->next; // move first by 2 nodes 
        if(slow == fast){ // if slow and firsst meets then definetly theare is an cycle
            return true;
        }      
    }
    return false;
    }
};