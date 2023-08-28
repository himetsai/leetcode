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

    int maxSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = maxSum(root->left);
        int right = maxSum(root->right);
        int maxEndWithRoot = (left <= 0 && right <= 0) ? root->val : max(left + root->val, right + root->val);
        ans = max(max(left + right + root->val, maxEndWithRoot), ans);
        return maxEndWithRoot;
    }

    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};