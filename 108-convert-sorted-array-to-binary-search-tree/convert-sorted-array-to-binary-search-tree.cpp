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
// Code with Radheshyam (.^.) 

    TreeNode* bst(vector<int>& nums,int left,int right){
        // Base case
        if(left > right) return NULL;
        int mid = (left+right)/2;
        // Recursive case
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums,left,mid-1);
        root->right = bst(nums,mid+1,right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return NULL;
        return bst(nums,0,n-1);

    }
};