/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){return "";}
    string s="";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* r=q.front();
        q.pop();
        if(!r){s+="#,";}
        else{s+=(to_string(r->val)+",");}
        if(r!=NULL){
            q.push(r->left);
            q.push(r->right);
        }
    }
    return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){return NULL;}
    stringstream x(data);
    string str="";
    getline(x, str, ',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* rt=q.front();
        q.pop();
        getline(x, str, ',');
        if(str=="#"){
            rt->left=NULL;
        }
        else{
            TreeNode* lft=new TreeNode(stoi(str));
            rt->left=lft;
            q.push(lft);
        }
        getline(x, str, ',');
        if(str=="#"){rt->right=NULL;}
        else{
            TreeNode* rgt=new TreeNode(stoi(str));
            rt->right=rgt;
            q.push(rgt);
        }
    }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));