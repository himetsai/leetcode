class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, l = 0;
        int zero = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (!nums[r]) {
                if (!zero)
                    zero = 1;
                else {
                    while (nums[l] && l < r) l++;
                    l++;
                }
            }
            ans = max(r - l, ans);
        }
        return ans;
    }
};