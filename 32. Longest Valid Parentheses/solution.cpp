class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            if (st.empty()) continue;
            if (dp[i - 1] == i - st.top() - 1) dp[i] = dp[i - 1] + 2;
            if (st.top() > 0) dp[i] += dp[st.top() - 1];
            st.pop();
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};