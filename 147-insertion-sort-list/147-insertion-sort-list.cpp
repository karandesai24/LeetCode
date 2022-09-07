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
    ListNode* insertionSortList(ListNode* head) {
         ListNode *nxt = head -> next;
    while(nxt != NULL)
    {
        ListNode *curr = head;
        while(curr != nxt)
        {
            if(nxt -> val < curr -> val)
                swap(curr -> val, nxt -> val);
            
            curr = curr -> next;
        }
        nxt = nxt -> next;   
    }
    return head;
    }
};