class Solution {
public:
    TreeNode* addOneRowh(TreeNode* r, int val, int depth, int side){
        if(!r ){
            if(depth == 1) return new TreeNode(val);
            return r;
        };
        
        if(depth == 1){
            TreeNode* n = new TreeNode(val);
            if(!side) n->left = r; // Side = 0 Insert subtree into the left of new node
            else n->right = r; // Side = 1 Insert subtree into the right of new node
            return n;
        }
        
        r->left = addOneRowh(r->left, val, depth-1, 0);  // Add Node into left tsub ree 
        r->right = addOneRowh(r->right, val, depth-1, 1); // Add Node into right sub Tree
        
        return r;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return addOneRowh(root, val, depth, 0);
    }
};
