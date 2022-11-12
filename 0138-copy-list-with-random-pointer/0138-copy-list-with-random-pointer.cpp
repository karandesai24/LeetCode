/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* temp = head;
        
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        
        temp = head;
        while(temp){
            temp->next->random = (temp->random)?temp->random->next:NULL;
            temp = temp->next->next;
        }
        
        Node* ans = head->next;
        temp = head->next;
        while(head){
            head->next = temp->next;
            head = head->next;
            if(!head) break;
            temp->next = head->next;
            temp = temp->next;
        }
        return ans;
    }
};
/*
  Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*>mp;
        Node *temp=head;
        while(temp)
        {
            Node *newnode=new Node(temp->val);
            mp[temp]=newnode;
            temp=temp->next;
        }
        Node *t=head;
        while(t)
        {
            Node *answer=mp[t];
            answer->next=t->next?mp[t->next]:NULL;
            answer->random=t->random?mp[t->random]:NULL;
            t=t->next;
        }
        return mp[head];
    }
    */