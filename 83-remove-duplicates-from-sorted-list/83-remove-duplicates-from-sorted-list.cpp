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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* last = head;
        ListNode* cur = head->next;
        
        while(cur != NULL){
            if(cur->val == last->val){
                //remove cur
                last->next = cur->next;
            }else{
                //update last only if cur isn't duplicate
                last = cur;
            }
            cur = cur->next;
        }
        
        return head;
       
    }
};

/*
  ListNode* curr = head;

    while (curr) {
      while (curr->next && curr->val == curr->next->val)
        curr->next = curr->next->next;
      curr = curr->next;
    }

    return head;
    */
