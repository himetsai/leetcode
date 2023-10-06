class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int p0 = nums[0], p1 = max(nums[0], nums[1]);
        if (nums.size() == 2) return p1;
        for (int i = 2; i < nums.size() - 1; i++) {
            int temp = p1;
            p1 = max(p0 + nums[i], p1);
            p0 = temp;
        }
        int ans = p1;
        p0 = nums[1];
        p1 = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            int temp = p1;
            p1 = max(p0 + nums[i], p1);
            p0 = temp;
        }
        return max(ans, p1);
    }
};