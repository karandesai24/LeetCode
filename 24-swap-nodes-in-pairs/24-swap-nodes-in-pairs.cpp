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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        { 
            return head;
        }
        ListNode* slow =head,*fast=head->next;

    while(fast!=NULL && (fast->next)!=NULL)
    { 
      swap(slow->val,fast->val);
        slow=slow->next->next;
        fast=fast->next->next;
        }
    if(slow!=NULL && fast!=NULL)
    {  
        swap(slow->val,fast->val);
    }
        

    return head;
    }
};