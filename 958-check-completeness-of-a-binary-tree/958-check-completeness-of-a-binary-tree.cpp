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
    int countNode(struct TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int ans= 1+countNode(root->left)+countNode(root->right);
        return ans;
    }
    bool isCBT(struct TreeNode* root,int index,int cnt)
    {
         if(root==nullptr)
        {
            return 1;
        }
         if(index>=cnt)
        {
            return false;
        }
        else{
            bool left=isCBT(root->left,2*index+1,cnt);
             bool right=isCBT(root->right,2*index+2,cnt);
            return (left && right);
        }
    }
    bool isCompleteTree(TreeNode* root) {
        int index=0;
        int totalCount= countNode(root);
        if(isCBT(root,index,totalCount))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};