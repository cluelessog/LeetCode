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
    int sum = 0;
    void pathSum(TreeNode* root, int currPath, int& sum)
    {
        if(!root)
            return;
        currPath = 10*currPath + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += currPath;
            return;
            
        }
        
            pathSum(root->left,currPath,sum);
            pathSum(root->right,currPath,sum);
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        pathSum(root,0,sum);
        return sum;
    }
};
