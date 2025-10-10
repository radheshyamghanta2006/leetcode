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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Code with Rasdheshyam (.^.)
        vector<vector<int>>ans;
        if (root == NULL) return ans;
        queue<TreeNode *>q;
        int flag=0;
        q.push(root);
        while(!q.empty()){
            flag=!flag;
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *ele=q.front();
                q.pop();
                temp.push_back(ele->val);
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            // Zig zag case
            if(flag==0) reverse(temp.begin(),temp.end());
                ans.push_back(temp);
        }
        return ans;
    }
};