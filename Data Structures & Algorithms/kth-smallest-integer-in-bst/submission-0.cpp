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
    void dfs(TreeNode* root, multiset<int>&ms) {
        if(not root) return;
        ms.insert(root->val);
        dfs(root->left,ms);
        dfs(root->right, ms);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        multiset<int> ms;
        dfs(root,ms);
        int val = -1;
        auto it = ms.begin();
        while(k--) {
            val = *it;
            it++;
        }
        return val;
    }
};
