class Solution {
public:
    vector<string> recur(int n, vector<vector<string>>& dp) {
        if (!dp[n].empty()) return dp[n];
        vector<string> v;
        for (int i = 0; i < n; i++) {
            for (string s1 : recur(i, dp)) {
                for (string s2 : recur(n-i-1, dp))
                    v.push_back(s1 + '(' + s2 + ')');
            }
        }
        dp[n] = v;
        return v;
    }

    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        
        return recur(n, dp);
    }
};