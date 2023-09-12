class Solution {
public:
    vector<vector<string>> ans;
    int count = 0;
    vector<string> strs;

    void recur(int i, int n, vector<bool>& row, vector<bool>& col, vector<bool>& diagPos, vector<bool>& diagNeg) {
        if (count >= n) {
            ans.push_back(strs);
            return;
        }
        if (i >= n * n)
            return;
        int r = i / n;
        int c = i % n;
        if (row[r] && col[c] && diagPos[r + c] && diagNeg[c - r + n - 1]) {
            row[r] = false;
            col[c] = false;
            diagPos[r + c] = false;
            diagNeg[c - r + n - 1] = false;
            count++;
            strs[r][c] = 'Q';
            recur(i + 1, n, row, col, diagPos, diagNeg);
            strs[r][c] = '.';
            count--;
            row[r] = true;
            col[c] = true;
            diagPos[r + c] = true;
            diagNeg[c - r + n - 1] = true;
        }
        recur(i + 1, n, row, col, diagPos, diagNeg);
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> row(n, true);
        vector<bool> col(n, true);
        vector<bool> diagPos(2 * n - 1, true);
        vector<bool> diagNeg(2 * n - 1, true);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++)
                s.push_back('.');
            strs.push_back(s);
        }
        recur(0, n, row, col, diagPos, diagNeg);
        return ans;
    }
};