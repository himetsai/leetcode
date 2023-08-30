/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        TreeNode* l = root;
        TreeNode* r = root;
        while (l == r) {
            ans = l;
            if (p->val < l->val) l = l->left;
            else if (p->val > l->val) l = l->right;
            if (q->val < r->val) r = r->left;
            else if (q->val > r->val) r = r->right;
        }
        return ans;
    }
};