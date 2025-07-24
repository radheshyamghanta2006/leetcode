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
    // Code with Radheshyam (.^.)
public:
    ListNode* swapPairs(ListNode* head) {
        // Taking a dummy node for point the head
        ListNode* dHead = new ListNode(-1);
        dHead->next = head;
        ListNode* point = dHead;

        while(point->next != NULL && point->next->next != NULL){
            // Identify the nodes for swapint
            ListNode* swap1 = point->next;
            ListNode* swap2 = point->next->next;
            // Perform swaping
            swap1->next = swap2->next;
            swap2->next = swap1;
            // Now move pointer for next swaping
            point->next = swap2;
            point = swap1;
        }
        return dHead->next;
    }
};