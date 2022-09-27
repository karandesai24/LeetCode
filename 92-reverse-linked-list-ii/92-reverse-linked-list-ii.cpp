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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
             if(head==NULL || head->next==NULL || left==right)
                 return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        //1) Reach at position left :-
        ListNode * leftPrev = dummy;
        ListNode*curr = head;
        int cnt = left-1;
        while(cnt--){
            leftPrev = curr;
            curr = curr->next;
        }
        
        
        ListNode * prev = NULL;
        cnt = right-left+1;
        ListNode * frwd = NULL;
        //2) Reversing from left to right.
        while(cnt--){
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        
        //3)
        leftPrev->next->next = curr;
        leftPrev->next = prev;
        
        return dummy->next; 
    }
};
/*
ListNode* temp=head;
vector<int> v;
while(temp)
{
v.push_back(temp->val);
temp=temp->next;
}
reverse(v.begin()+left-1,v.begin()+right);
temp=head;
int i=0;
while(temp)
{
temp->val=v[i];
i++;
temp=temp->next;
}
return head;
*/