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

    int solve(TreeNode* root, int &k)
    {
        if(!root)
            return 0;
        
        int left = solve(root->left,k);
        if(left)
            return left;
        k-=1;
        if(k==0)
            return root->val;
        int right = solve(root->right,k);
        return right;
    }
    // Code with Radheshyam (.^.)
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};