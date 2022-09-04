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
    ListNode* rotateRight(ListNode* head, int k) {
         ListNode* temp = head;
        
        if(temp==NULL) return NULL;
        if(k==0) return temp;
        
        int sz = 1;
        while(temp->next != NULL){
            sz++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%sz;
        k = sz-k;
        ListNode* ans =temp;
        while(k--) ans = ans->next;
        
        head = ans->next;
        ans->next = NULL;
        
        return head;
    }
};