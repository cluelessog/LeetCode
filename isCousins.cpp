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
    int Depth(TreeNode* root, int x,int level)
    {  
        if(root == NULL)
        {
            return 0;
        }
        if(root->val == x)
        {
            return level;
        }
        int depth = Depth(root->left, x,level+1);
        if(depth != 0 )
        {
            return depth;
        }
        depth = Depth(root->right, x,level+1);
        
        return depth;
        
    }

    int Parent(TreeNode* root,int x)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left != NULL)
        {
            if(root->left->val == x)
            {
                return root->val;
            }
        }
        if(root->right != NULL)
        {
            if(root->right->val == x)
            {
                return root->val;
            }
        }
        int parent = Parent(root->left,x);
        if(parent != 0)
        {
            return parent;
        }
        parent = Parent(root->right,x);
        return parent;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = Depth(root,x,0);
        int yDepth = Depth(root,y,0);
        int xParent = Parent(root,x);
        int yParent = Parent(root,y);
        cout << xDepth << " " << yDepth << endl;
        cout << xParent << " " << yParent << endl;
        if(xDepth == yDepth)
        {
            if(xParent != yParent)
            {
                return true;
            }
        }
        return false;
    }
};
