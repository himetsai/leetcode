class Solution {
public:
    vector<string> ans;
    unordered_set<string> set;
    vector<vector<bool>> visited;
    string s = "";
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    struct node {
        vector<node*> children;
        bool isWord;
        node(): children(26, nullptr), isWord(false) {}
    };

    void dfs(vector<vector<char>>& board, int i, int j, node* n) {
        if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size() || visited[i][j]) 
            return;
        if (n->children[board[i][j] - 'a'] == nullptr) return;
        visited[i][j] = true;
        s.push_back(board[i][j]);
        if (n->children[board[i][j] - 'a']->isWord) set.insert(s);
        for (auto d : dir)
            dfs(board, i + d[0], j + d[1], n->children[board[i][j] - 'a']);
        s.pop_back();
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* trie = new node();
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (string s : words) {
            node* curr = trie;
            for (char c : s) {
                if (curr->children[c - 'a'] == nullptr) 
                    curr->children[c - 'a'] = new node();
                curr = curr->children[c - 'a'];
            }
            curr->isWord = true;
        }

        for (int i = 0; i < board.size(); i++) {
            if (set.size() == words.size()) break;
            for (int j = 0; j < board[0].size(); j++) {
                if (set.size() == words.size()) break;
                dfs(board, i, j, trie);
            }
        }
        for (string str : set)
            ans.push_back(str);
        return ans;
    }
};