class Solution {
public:
    vector<string> v;
    vector<vector<string>> ans;

    bool isPal(string s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--]) return false;
        return true;
    }
    
    void recur(string s, int start) {
        if (start == s.length()) {
            ans.push_back(v);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (!isPal(s, start, i)) continue;
            v.push_back(s.substr(start, i - start + 1));
            recur(s, i + 1);
            v.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        recur(s, 0);
        return ans;
    }
};