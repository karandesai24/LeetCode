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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return  NULL;
    
    ListNode* even = head->next;
    ListNode* odd = head;
    ListNode* evnOdd = even;
    
    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evnOdd;
    return  head;
    }
};
/*
vector<int>vec;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        vec.push_back(temp->val);
        temp=temp->next;
    }

    int n=vec.size();
    vector<int>odd,even;
    for(int i=0;i<vec.size();i++)
    {
        if(i%2==0)
            even.push_back(vec[i]);
        else 
            odd.push_back(vec[i]);
    }
    vector<int>ans;
    for(auto x:even)
    {
        ans.push_back(x);
    }
    for(auto y:odd)
    {
        ans.push_back(y);
    }
    int i=0;
    ListNode* ptr=head;
    while(ptr!=NULL)
    {
        ptr->val=ans[i];
        ptr=ptr->next;
        i++;
    }
    ptr=head;
    return ptr;

*/