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
    
        vector<int> v;
    void largest(TreeNode* root,int h){
        if(root==NULL) return;
        if(v.size()<h+1) v.push_back(root->val);
        else v[h]=max(v[h],root->val);
        largest(root->left,h+1);
        largest(root->right,h+1);
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        largest(root,0);
        return v;
    }
};