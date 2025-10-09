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
    // Code with Radheshyam(.^.)
public:
    void postOrder(TreeNode* root,vector<int> &ans){
        // Base case
        if(root == NULL) return;
        // Recursive case
        postOrder(root->left,ans); // Left
        postOrder(root->right,ans); // Right
        ans.push_back(root->val); // Push the ans
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root,ans);
        return ans;
    }
};