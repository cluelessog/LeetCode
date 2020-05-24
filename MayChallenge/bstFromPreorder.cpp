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
    int index = 0;
    TreeNode* helper(vector<int>& preorder,int min, int max)
    {
        if(index >= preorder.size()) return NULL;
        TreeNode *node = NULL;
        int key = preorder[index];
        if(min < key && key < max)
        {
            node = new TreeNode(key);
            index++;
            node->left = helper(preorder,min,key);
            node->right = helper(preorder,key,max);
        }
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
       /* stack solution 
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        for(int i = 1 ; i < preorder.size(); i++)
        {
            TreeNode* temp = NULL;
            while(!s.empty() && preorder[i] > s.top()->val)
            {
                temp = s.top();
                s.pop();
            }
            TreeNode *node = new TreeNode(preorder[i]);
            if(temp != NULL)
            {
                temp->right = node;  
            }
            else
            {
                s.top()->left = node;
            }
            s.push(node);
        }
        return root; */
        return helper(preorder,INT_MIN,INT_MAX);
    }
};
