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
    
    int lheight(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + lheight(root->left);
    }
    int rheight(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + rheight(root->right);
    }
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int leftHeight = lheight(root);
        int rightHeight = rheight(root);
        
        if(leftHeight == rightHeight)
            return pow(2,leftHeight) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
