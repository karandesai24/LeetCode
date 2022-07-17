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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
          TreeNode* root = converter(0, preorder.size()-1, preorder);
        return root;
    }
private:
    TreeNode* converter(int start, int end, vector<int>& preorder){
        if( start > end ) return nullptr;
        // catch the start number as a root
        TreeNode* root = new TreeNode(preorder[start]);
        // search the separation point
        int count = start+1;
        while( count <= end ){
            if( preorder[count] < preorder[start] ) count++;
            else break;
        }
        root->left = converter(start+1, count-1, preorder);
        root->right = converter(count, end, preorder);
        return root;
    }
};