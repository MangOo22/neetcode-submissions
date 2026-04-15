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
    int dfs(TreeNode* root, int maxSoFar) {
        if (not root) return 0;
        bool isValid = (root->val >= maxSoFar);
        return isValid + dfs(root->left, max(maxSoFar,root->val)) + 
                         dfs(root->right, max(maxSoFar,root->val));
                          
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,-110);
    }
};
