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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int size = q.size();
            TreeNode* rightSideNode = nullptr;
            for (int i = 0; i < size; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode) {
                    rightSideNode = curNode;
                    q.push(curNode->left);
                    q.push(curNode->right);
                }
            }
            if (rightSideNode) res.push_back(rightSideNode->val);
        }
        return res;
    }
};
