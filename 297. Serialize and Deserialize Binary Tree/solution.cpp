/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string s;
    int curr;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        string ans = to_string(root->val);
        ans.push_back(','),
        ans += serialize(root->left);
        ans.push_back(',');
        ans += serialize(root->right);
        return ans;
    }

    TreeNode* dfs() {
        if (curr >= s.length()) return nullptr;
        int end = curr;
        int start = curr;
        while (end < s.length() && s[end] != ',') end++;
        curr = end + 1;
        if (s[start] == '#') return nullptr;
        TreeNode* root = new TreeNode(stoi(s.substr(start, end - start)));
        root->left = dfs();
        root->right = dfs();
        return root;
    }

    // Decodes your encoded data to tree.
    // 1,2,#,#,3,4,#,#,5,#,#
    // 1,2,3,4,#
    TreeNode* deserialize(string data) {
        s = data;
        curr = 0;
        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));