class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long ans = 1;
        int small = min(m - 1, n - 1);
        for (int i = 1; i <= small; i++) {
            ans *= m + n - 1 - i;
            ans /= i;
        }
        return ans;
    }
};