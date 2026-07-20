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
    int ans = INT_MIN;
    int traverse(TreeNode* root){
        if (root == NULL) return 0;
        if (root-> right == NULL && root->left == NULL) {
            ans = max(ans,root->val);
            return root->val;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        if (root->left == NULL && root->val < 0 && root->right == NULL){
            ans = max(ans,root->val);
        }
        else if (root->right == NULL && root->val < 0){
            ans = max(left,ans);
            ans = max(ans,root->val);
            ans = max(ans, left + root->val);
        } else if (root->left == NULL && root->val < 0){
            ans = max(ans,root->val);
            ans = max(right,ans);
            ans = max(ans,right+root->val);
        } else {
            ans = max(left,ans);
            ans = max(right,ans);
            ans = max(ans, left+right+root->val);
            ans = max(ans, left + root->val);
            ans = max(ans,right+root->val);
            ans = max(ans,root->val);
        }
        if (left < 0 && right < 0) return root->val;
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int temp = traverse(root);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna