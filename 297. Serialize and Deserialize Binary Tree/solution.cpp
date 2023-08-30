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
    int curr = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (root == nullptr) return ans;
        ans += to_string(root->val);
        if (!root->left && !root->right) return ans;
        ans.push_back('(');
        if (root->left)
            ans += serialize(root->left);
        ans.push_back(',');
        if (root->right)
            ans += serialize(root->right);
        ans.push_back(')');
        return ans;
    }

    // Decodes your encoded data to tree.
    // 5(300(,-4),),2(7,))
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        int start = curr;
        int len = 0;
        while (start + len < data.length() && data[start + len] != '(' && data[start + len] != ')' && data[start + len] != ',') 
            len++;
        curr = start + len + 1;
        if (len == 0) return nullptr;
        TreeNode* root = new TreeNode(stoi(data.substr(start, len)));
        if (start + len >= data.length()) return root;
        if (data[start + len] == '(') {
            root->left = deserialize(data);
            root->right = deserialize(data);
            curr++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));