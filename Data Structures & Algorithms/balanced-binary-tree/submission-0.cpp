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
    int height(TreeNode *root) {
        if (not root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(not root) return 1;
        int l = height(root->left);
        int r = height(root->right);
        if (abs(l - r) <= 1 and isBalanced(root->left) and 
            isBalanced(root->right)) {
            return true;
        } else {
            return false;
        }
    }
};
