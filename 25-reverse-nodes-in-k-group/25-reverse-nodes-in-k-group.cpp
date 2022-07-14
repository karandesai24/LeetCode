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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        
        int steps = 0;
        
        for(; steps < k && cur; ++steps){
            cur = cur->next;
        }
        
        //list's length < k, don't need to reverse
        if(steps < k) return head;
        
        //now cur is the head of next group, reverse that group first
        cur = reverseKGroup(cur, k);
        
       
        for(int i = 0; i < k; ++i){
            //"head": head of the list to be reversed
            ListNode* tmp = head->next;
            //cur: head of reversed list
            head->next = cur;
            cur = head;
            head = tmp;
        }
        
        return cur;
    }
};