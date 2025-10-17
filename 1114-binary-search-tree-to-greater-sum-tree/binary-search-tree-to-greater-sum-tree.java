/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int sum = 0;
    void dfs(TreeNode root){
    //base case
    if(root == null){
        return;
    }
    // recursive case
    dfs(root.right);
    sum += root.val;
    root.val = sum;
    dfs(root.left);
}
    public TreeNode bstToGst(TreeNode root) {
        // Code with Radheshyam (.^.)
        dfs(root);
        return root;
    }
}