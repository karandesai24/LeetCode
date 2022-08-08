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

   void travel(TreeNode* root, int& cur_num, int& res){
        if( !root ) 
            return;
       cur_num = cur_num * 10 + root->val;
        if( !root->left && !root->right )
            res += cur_num;
        if( root->left ) 
            travel(root->left, cur_num, res);
        if( root->right ) 
            travel(root->right, cur_num, res);
        cur_num = (cur_num - root->val) / 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int cur_num = 0, res = 0;
        travel(root, cur_num, res);
        return res;
    }
};