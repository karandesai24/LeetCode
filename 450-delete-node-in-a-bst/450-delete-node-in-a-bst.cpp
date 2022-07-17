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
  TreeNode* getMin(TreeNode* node) {
    while (node->left)
      node = node->left;
    return node;
  }
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==nullptr)
        {
            return root;
        }
       if (root->val== key)
        {
            if(root->left ==nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
             if(root->left !=nullptr && root->right == nullptr)
             {
                 TreeNode* temp = root->left;
                 delete root;
                 return temp;
             }
           if(root->left ==nullptr && root->right != nullptr)
           {
               TreeNode* temp = root->right;
               delete root;
               return temp;
           }
           if(root->left !=nullptr && root->right != nullptr)
           {
               int mini =getMin(root->right)->val;
               root->val=mini;
               root->right=deleteNode(root->right,mini);
               return root;
           }
        }
        else if (root->val >key)
        {
            root->left=deleteNode(root->left,key);
        return root;
        }
        else {
            root->right= deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};