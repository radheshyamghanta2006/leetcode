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
//Code with Radheshyam (.^.)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=new ListNode(-1);
    ListNode *pre=head;
    ListNode *temp=NULL;
    
    
while(list1!=NULL && list2!=NULL){
    if(list1->val > list2->val){
        pre->next=list2;
        temp=list2->next;
        list2->next=NULL;
        pre=list2;
        list2=temp;
    }else{
         pre->next=list1;
        temp=list1->next;
        list1->next=NULL;
        pre=list1;
        list1=temp;
    }
    }
    
    if(list1==NULL)pre->next=list2;
    if(list2==NULL)pre->next=list1;
    
    return head->next;
    }
};