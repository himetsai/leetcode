class Solution {
public:
    // returns length
    int expand(string s, int l, int r) {
        if (r < l || l < 0 || r >= s.length()) return -1;
        while (l >= 0 && r < s.length()) {
            if (s.at(l) != s.at(r)) break;
            l--;
            r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        int max = 0;
        int l, len;
        for (int i = 0; i < s.length(); i++) {
            len  = expand(s, i, i);
            if (max < len) {
                max = len;
                l = i - len / 2;
            }
            len  = expand(s, i, i + 1);
            if (max < len) {
                max = len;
                l = i - len / 2 + 1;
            }
        }
        return s.substr(l, max);
    }
};