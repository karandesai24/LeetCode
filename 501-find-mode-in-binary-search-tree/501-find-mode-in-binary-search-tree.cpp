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
     void helper(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr) return;
        if (root) mp[root->val]++;
        helper(root->left, mp);
        helper(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        helper(root, mp);
        vector<int> res;
        int max = 0;
        unordered_map<int, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr->second == max)
                res.push_back(itr->first);
            if (itr->second > max) {
                max = itr->second;
                res.clear();
                res.push_back(itr->first);
            }
        }
        return res;
    }
};