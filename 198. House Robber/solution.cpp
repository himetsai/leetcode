class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int i1 = nums[0], i2 = max(nums[0], nums[1]);
        int ans = i2;
        for (int i = 2; i < nums.size(); i++) {
            ans = max(i1 + nums[i], i2);
            i1 = i2;
            i2 = ans;
        }
        return ans;
    }
};