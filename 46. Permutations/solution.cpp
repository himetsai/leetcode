class Solution {
public:
    vector<vector<int>> ans;

    void recur(vector<int>& nums, vector<int> v) {
        if (v.size() == nums.size()) ans.push_back(v);
        for (int i : nums) {
            if (find(v.begin(), v.end(), i) != v.end()) continue;
            v.push_back(i);
            recur(nums, v);
            v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        recur(nums, v);
        return ans;
    }
};