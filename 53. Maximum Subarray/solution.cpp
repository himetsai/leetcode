class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local[nums.size()];
        int ans = 0;
        local[0] = nums[0];
        ans = local[0];
        for (int i = 1; i < nums.size(); i++) {
            local[i] = max(nums[i], local[i-1] + nums[i]);
            ans = max(local[i], ans);
        }
        return ans;
    }
};