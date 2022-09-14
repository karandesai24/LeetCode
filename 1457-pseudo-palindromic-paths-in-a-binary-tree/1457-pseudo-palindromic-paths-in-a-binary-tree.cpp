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
 int count = 0;
    
    void dfs(TreeNode* root, vector<int> mp)
    {
       
        if(root == NULL)
        {
            return;
        }
        
        
        mp[root -> val]++;
        
        if(root -> left == NULL && root -> right == NULL)
        {
            int odd_count = 0;
            
            for(auto x : mp)
            {
                if(x % 2)
                {
                    odd_count++;
                }
            }
            
            if(odd_count <= 1)
            {
                count++;
            }
            
            return;
        }
             
        dfs(root -> left, mp);
        
        
        dfs(root -> right, mp);
    }

    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> mp(10, 0);
        
        dfs(root, mp);
        
        return count;
    }
};