class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i = 0, j = 0;
        int total = matrix.size() * matrix[0].size();
        ans.push_back(matrix[i][j]);
        matrix[i][j] = 101;
        while (ans.size() < total) {
            while (j < matrix[0].size() - 1 && matrix[i][j + 1] != 101) {
                ans.push_back(matrix[i][++j]);
                matrix[i][j] = 101;
            }
            while (i < matrix.size() - 1 && matrix[i + 1][j] != 101) {
                ans.push_back(matrix[++i][j]);
                matrix[i][j] = 101;
            }
            while (j > 0 && matrix[i][j - 1] != 101) {
                ans.push_back(matrix[i][--j]);
                matrix[i][j] = 101;
            }
            while (i > 0 && matrix[i - 1][j] != 101) {
                ans.push_back(matrix[--i][j]);
                matrix[i][j] = 101;
            }
        }
        return ans;
    }
};