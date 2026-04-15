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
    unordered_map<TreeNode*, int> height;
    int calcHeight(TreeNode* root) {
        if (not root) return 0;
        int l = calcHeight(root->left);
        int r = calcHeight(root->right);
        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
       if (not root) return 1;
       int left = calcHeight(root->left);
       int right = calcHeight(root->right);
       int diff = abs(left - right);
       if (diff > 1) return false;
       if (isBalanced(root->left) and 
           isBalanced(root->right)) {
            return true;
           }
        return false;
    }
};
