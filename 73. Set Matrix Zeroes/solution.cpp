class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto i = row.begin(); i != row.end(); i++) {
            for (int j = 0; j < matrix[*i].size(); j++) {
                matrix[*i][j] = 0;
            }
        }

        for (auto i = col.begin(); i != col.end(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][*i] = 0;
            }
        }
    }
};