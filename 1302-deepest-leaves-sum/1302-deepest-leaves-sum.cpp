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
    int deepestLeavesSum(TreeNode* root) {
         if(root==NULL)
            return 0;
        queue<TreeNode*>q;
        int sum=0;
        q.push(root);
        TreeNode*ptr=NULL;
        q.push(ptr);
        while(1)
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==ptr)
            {
                if(q.empty())
                {
                    return sum;
                }
                sum=0;
                q.push(ptr);
            }
            else{
                sum+=temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
        return 0;
    }
};