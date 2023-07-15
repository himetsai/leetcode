class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix[nums.size()];
        int suffix[nums.size()];
        vector<int> ans(nums.size());
        prefix[0] = nums[0];
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] * prefix[i-1];
            suffix[nums.size() - i - 1] = nums[nums.size() - i - 1] * suffix[nums.size() - i];
        }
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = (i == 0 ? 1 : prefix[i-1]) * (i == nums.size() - 1 ? 1 : suffix[i+1]);
        }
        return ans;
    }
};