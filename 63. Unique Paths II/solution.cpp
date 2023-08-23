class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[obstacleGrid.size()][obstacleGrid[0].size()];
        int k = 0;
        bool valid = true;
        while (k < obstacleGrid.size()) {
            if (obstacleGrid[k][0] == 1) valid = false;
            dp[k][0] = (valid) ? 1 : 0;
            k++;
        }
        k = 0;
        valid = true;
        while (k < obstacleGrid[0].size()) {
            if (obstacleGrid[0][k] == 1) valid = false;
            dp[0][k] = (valid) ? 1 : 0;
            k++;
        }

        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++)
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i-1][j] + dp[i][j-1];
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};