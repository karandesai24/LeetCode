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
    int search(vector<int> inorder, int start, int end, int curr)
    {
        for(int i=start; i<=end; i++)
        {
            if(inorder[i]== curr)
            {
                return i;
            }
        }
        return -1;
    }
    
    int idx= 0;
    TreeNode* build(vector<int> inorder, vector<int> preorder, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }
        int curr= preorder[idx];
        TreeNode* root= new TreeNode(curr);
        idx++;
        int pos= search(inorder, start, end, curr);
        root->left= build(inorder, preorder, start, pos-1);
        root->right= build(inorder, preorder, pos+1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n= inorder.size();
        return build(inorder, preorder, 0, n-1);
    }
};