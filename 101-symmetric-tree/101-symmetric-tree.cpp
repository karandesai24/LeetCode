/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return fun(root->left,root->right);
    }
    bool fun(TreeNode *p,TreeNode *q)
     
   {
       if(p==NULL and q==NULL)
           return true;
       if(p==NULL or q==NULL or p->val!=q->val)
           return false;
       return fun(p->left,q->right) and fun(p->right,q->left);
    }
};