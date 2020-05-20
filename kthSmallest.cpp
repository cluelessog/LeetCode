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
// class Solution {
//     vector<int> arr;
//     vector<int> inorder(TreeNode *root)
//     {
//         if(root == NULL) return arr;
//         inorder(root->left);
//         arr.push_back(root->val);
//         inorder(root->right);
//         return arr;
//     }
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         if(root == NULL) return 0;
//         vector<int> res = inorder(root);
//         return res[k-1];
//     }
// };
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            TreeNode* top = s.top();
            if(!(--k)) return top->val;
            s.pop();
            root = top->right;
        }
        return -1;
    }
};
