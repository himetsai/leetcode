class Solution {
public:
    vector<vector<int>> ans;

    void recur(vector<int>& candidates, vector<int>& v, int start, int target) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if (target < 0 || start >= candidates.size()) return;

        for (int i = start; i < candidates.size(); i++) {
            v.push_back(candidates[i]);
            recur(candidates, v, i, target - candidates[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        recur(candidates, v, 0, target);
        return ans;
    }
};