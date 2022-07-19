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
   TreeNode* convertBST(TreeNode* root) {
        if( !root ) return nullptr;
        root -> right = convertBST( root -> right );
        root -> val += count;
        count = root -> val;
        root -> left = convertBST( root -> left );
        return root;
    }
private:
    int count = 0;
};