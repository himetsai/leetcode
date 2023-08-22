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
    stack<TreeNode*> st;
    vector<int> ans;

    bool dfs(TreeNode* root, TreeNode* target) {
        if (root == NULL) return false;
        st.push(root);
        if (root == target) return true;
        if (dfs(root->left, target)) return true;
        if (dfs(root->right, target)) return true;
        st.pop();
        return false;
    }

    void getK(TreeNode* root, int k) {
        if (k < 0 || root == NULL || root->val == -1) return;
        if (k == 0) ans.push_back(root->val);
        getK(root->left, k - 1);
        getK(root->right, k - 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, target);
        while (!st.empty() && k >= 0) {
            TreeNode* temp = st.top();
            st.pop();
            getK(temp, k);
            temp->val = -1;
            k--;
        }
        return ans;
    }
};