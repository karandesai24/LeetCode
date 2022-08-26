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
        return helper(l1,l2,0);
    }
    
    ListNode* helper(ListNode* l1,ListNode* l2, int carry){
        if(!l1 && !l2 && carry==0)return NULL;
        int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
        ListNode* Node= new ListNode(sum%10);
        Node->next=helper(l1?l1->next:NULL,l2?l2->next:NULL,sum/10);
        return Node;
    }
};