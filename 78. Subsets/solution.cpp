class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        for (int n : nums) {
            int size = ans.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                v = ans[i];
                v.push_back(n);
                ans.push_back(v);
            }
        }
        return ans;
    }
};