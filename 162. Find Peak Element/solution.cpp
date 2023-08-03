class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        int l = 1, r = nums.size() - 2;
        int m;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1]) return m;
            if (nums[m] < nums[m + 1]) l = m + 1;
            else r = m - 1;
        }
        return m;
    }
};