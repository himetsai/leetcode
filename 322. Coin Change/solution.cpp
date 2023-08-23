class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
            for (int v : coins) {
                if (v > i || dp[i - v] == -1) continue;
                dp[i] = min(dp[i], dp[i - v] + 1);
            }
            if (dp[i] == INT_MAX) dp[i] = -1;
        }
        return dp[amount];
    }
};