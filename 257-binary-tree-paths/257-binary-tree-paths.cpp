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
private:
    void inorder_traversal(TreeNode* root, string cur, vector<string>& res){
        if( !root ) return;
        cur += to_string(root->val);
        if( !root->left && !root->right ) res.push_back(cur);
        if( root->left ) inorder_traversal(root->left, cur + "->", res);
        if( root->right ) inorder_traversal(root->right, cur + "->", res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if( !root ) return {};
        vector<string> res;
        string cur = "";
        inorder_traversal(root, cur, res);
        return res;
    }
};