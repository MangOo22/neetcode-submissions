/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public int MaxPathSum(TreeNode root) {
        int ans = root.val;
        Dfs(root, ref ans);
        return ans;
    }
    int GetMaxPathSum(TreeNode root) {
        if(root is null) return 0;
        int left = GetMaxPathSum(root.left);
        int right = GetMaxPathSum(root.right);
        int sum = root.val + Math.Max(left,right);
        return Math.Max(0, sum);
    }    
    void Dfs(TreeNode root, ref int ans) {
        if (root is null) return;
        int left = GetMaxPathSum(root.left);
        int right = GetMaxPathSum(root.right);
        ans = Math.Max(ans, root.val + left + right);
        Dfs(root.left, ref ans); Dfs(root.right, ref ans);
    }
}
