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
     int search(vector<int> &inorder, int start, int end, int curr)
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
    int idx;
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }
        int curr= postorder[idx--];
        TreeNode* root= new TreeNode(curr);
        if(start== end)
        {
            return root;
        }
        int pos= search(inorder, start, end, curr);
        root->right= build(inorder, postorder, pos+1, end);
        root->left= build(inorder, postorder, start, pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n= inorder.size();
        idx= n-1;
        return build(inorder, postorder, 0, n-1);
    }
};