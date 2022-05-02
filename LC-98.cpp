class Solution {
    TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(!isValidBST(root->left))
            return false;
        
        if(prev && prev->val >= root->val) return false;
        prev = root;
        
        if(!isValidBST(root->right))
            return false;
        
        return true;
    }
};

// inorder traversal of the tree
