class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26, 0);
        for (char c : s) 
            f[c - 'a']++;
        
        char prev = '$';
        char curr;
        for (int i = 0; i < s.length(); i++) {
            int max = 0;
            for (int j = 0; j < 26; j++) {
                if (f[j] > max && j + 'a' != prev) {
                    max = f[j];
                    curr = j + 'a';
                }
            }
            if (curr == prev) return "";
            s[i] = curr;
            f[curr - 'a']--;
            prev = curr;
        }
        
        return s;
    }
};