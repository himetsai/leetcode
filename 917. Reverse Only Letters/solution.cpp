class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.length() - 1;
        if (l == r) return s;
        while (l < r) {
            while(!isalpha(s[l]) && l < r) l++;
            while(!isalpha(s[r]) && l < r) r--;
            if (l >= r) break;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};