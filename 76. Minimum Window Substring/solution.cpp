class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> correct = {};
        array<int, 128> curr = {};
        int l = 0, r = 0;
        int count = 0;
        int start = -1, len = s.length() + 1;
        for (char c : t)
            correct[c]++;
        for (int i = 0; i < 128; i++) 
            if (correct[i]) count++;
        
        while (r < s.length()) {
            if (count) {
                if (++curr[s[r]] == correct[s[r]])
                    count--;
                r++;
            }
                
            else
                if (curr[s[l]]-- == correct[s[l++]]) count++;
            if (!count && r - l < len) {
                len = r - l;
                start = l;
            }
        }

        while (!count && l < r) {
            if (curr[s[l]]-- == correct[s[l++]]) count++;
            if (!count && r - l < len) {
                len = r - l;
                start = l;
            }
        }
            
        return (start == -1) ? "" : s.substr(start, len);
    }
};