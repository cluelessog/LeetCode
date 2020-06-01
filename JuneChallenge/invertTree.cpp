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
    TreeNode* invertHelper(TreeNode* node)
    {
        if(node->left == NULL and node->right == NULL)
            return node;

        if(node->left != NULL)
            node->left = invertHelper(node->left);
        if(node->right != NULL)
            node->right = invertHelper(node->right);
        
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        return node;
    }
        
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        return invertHelper(root);
    }
};
