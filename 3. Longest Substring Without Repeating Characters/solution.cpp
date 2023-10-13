class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0;
        int window[128] = {};
        while (r < s.size() && l <= r) {
            while (l <= r && window[s[r]] > 0) 
                window[s[l++]]--;
            window[s[r++]]++;
            ans = max(r - l, ans);
        }
        return ans;
    }
};