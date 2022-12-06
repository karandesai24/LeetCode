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
      int maxLevelSum(TreeNode* root) {
        int res=0,level=1;
        queue<TreeNode*> q;
        q.push(root);
        long long mx=LONG_MIN;
        while(!q.empty()){
            int size=q.size();
            long long sum=0;
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                sum+=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(sum>mx){
                mx=sum;
                res=level;
            }
            level++;
        }
        return res;
    }
};