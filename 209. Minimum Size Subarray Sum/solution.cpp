class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0, ans = INT_MAX;
        while (l < nums.size()) {
            while (sum < target) {
                if (r >= nums.size()) break;
                sum += nums[r++];
            }
            if (sum >= target) ans = min(ans, r - l);
            sum -= nums[l++];
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};