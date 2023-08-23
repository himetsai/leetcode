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
    long prev = -2147483649;
    TreeNode* small;

    bool dfs(TreeNode* root) {
        if (root == nullptr) return true;
        if (!dfs(root->left)) return false;
        if (root->val <= prev) return false;
        prev = root->val;
        return dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        return dfs(root);
    }
};