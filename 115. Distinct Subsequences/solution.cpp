class Solution {
public:
    long recur(string& s, string& t, vector<vector<long>>& dp, int si, int ti) {
        if (ti >= t.size()) return 1;
        if (si >= s.size()) return 0;
        if (dp[si][ti] >= 0) return dp[si][ti];
        dp[si][ti] = (s[si] == t[ti]) * recur(s, t, dp, si + 1, ti + 1) + recur(s, t, dp, si + 1, ti);
        return dp[si][ti];
    }

    int numDistinct(string s, string t) {
        vector<vector<long>> dp(s.size(), vector<long>(t.size(), -1));
        return recur(s, t, dp, 0, 0);
    }
};