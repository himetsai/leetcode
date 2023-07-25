class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int ans = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int lmax = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                lmax = max(lmax, dp[j] + 1);
            }
            dp[i] = lmax;
            ans = max(ans, lmax);
        }
        return ans;
    }
};