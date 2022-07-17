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
    void flatten(TreeNode* root) {
        /*-------- morris-like-> o(n),o(1)-------------*/ 
        if (!root)
      return;

    while (root) {
      if (root->left) {
        // find the rightmost root
        TreeNode* rightmost = root->left;
        while (rightmost->right)
          rightmost = rightmost->right;
        // rewire the connections
        rightmost->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      // move on to the right side of the tree
      root = root->right;
    }
    }
};

/*------- recursion-> o(n),o(n)---------------
  if (!root)
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* const left = root->left;    // flattened left
    TreeNode* const right = root->right;  // flattened right

    root->left = nullptr;
    root->right = left;

    // connect the original right subtree
    // to the end of new right subtree
    TreeNode* rightmost = root;
    while (rightmost->right)
      rightmost = rightmost->right;
    rightmost->right = right;
*/

/*----------------- pre-order ---------------
 void flatten(TreeNode* root) {
        TreeNode* dummyHead = new TreeNode(0);
        preorder(root, dummyHead);
    }

    void preorder(TreeNode* root, TreeNode*& tail) {
        if (root == NULL)   return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        tail->right = root;
        tail = tail->right;
        root->left = NULL;


        preorder(left, tail);
        preorder(right, tail);
        */