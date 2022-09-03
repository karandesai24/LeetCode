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
    void reorderList(ListNode* head) {
       unordered_map<int, ListNode*> nodes;
        
        ListNode* curr=head;
        int i=0;
        while(curr){
            nodes[i++] = curr;
            curr = curr->next;
        }
        
        if(i<=2)
            return;

        int n = i, j=0;
        i--;
        while(j<i){
            nodes[j]->next = nodes[i];
            
            if(j+1 == i)
                nodes[i]->next = NULL;
            else
                nodes[i]->next = nodes[j+1];

            j++; i--;
        }
        
        if(n%2)
            nodes[j]->next = NULL;
    } 
    
};