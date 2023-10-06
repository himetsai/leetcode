class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int dp[matrix.size()][matrix[0].size()];
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (matrix[i][0] == '1') ans = 1;
        }
            
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            if (matrix[0][i] == '1') ans = 1;
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                ans = max(dp[i][j], ans);
            }
        }
        return ans * ans;
    }
};