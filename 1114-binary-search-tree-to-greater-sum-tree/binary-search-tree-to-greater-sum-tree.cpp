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
int sum=0;
void dfs(TreeNode *root){
    //base case
    if(root == NULL){
        return;
    }
    // recursive case
    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
}
    TreeNode* bstToGst(TreeNode* root) {
        // Code with Radheshyam (.^.)
        dfs(root);
        return root;
    }
};