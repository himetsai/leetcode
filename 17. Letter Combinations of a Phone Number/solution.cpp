class Solution {
public:
    string temp;
    vector<string> ans;

    void recur(string& digits, int ind, vector<vector<string>>& dict) {
        if (ind >= digits.length()) {
            if (temp.length())
                ans.push_back(temp);
            return;
        }
        for (string s : dict[digits[ind] - '0']) {
            temp += s;
            recur(digits, ind + 1, dict);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<string>> dict(10);
        temp = "";
        dict[2] = {"a", "b", "c"};
        dict[3] = {"d", "e", "f"};
        dict[4] = {"g", "h", "i"};
        dict[5] = {"j", "k", "l"};
        dict[6] = {"m", "n", "o"};
        dict[7] = {"p", "q", "r", "s"};
        dict[8] = {"t", "u", "v"};
        dict[9] = {"w", "x", "y", "z"};

        recur(digits, 0, dict);
        return ans;
    }
};