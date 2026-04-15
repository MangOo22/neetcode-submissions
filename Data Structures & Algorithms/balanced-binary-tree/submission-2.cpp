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
    // {balanced, height}
   vector<int> dfs(TreeNode* root) {
       if (not root) {
          return {1, 0};
       }
       auto left = dfs(root->left);
       auto right = dfs(root->right);
       bool balanced = (left[0] and right[0] and
                        (abs(left[1] - right[1]) < 2));
        int height = 1 + max(left[1], right[1]);
        return {balanced, height};
   }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
};
