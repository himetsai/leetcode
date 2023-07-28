class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, ans = 0;
        vector<int> window(26, 0);
        for (int i = 0; i < s.length(); i++) {
            window[s[i] - 'A']++;
            while (*max_element(window.begin(), window.end()) + k < i - l + 1) 
                window[s[l++] - 'A']--;
            ans = max(i - l + 1, ans);
        }
        return ans;
    }
};