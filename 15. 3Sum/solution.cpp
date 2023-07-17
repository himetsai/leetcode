class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> t;
        for (int n : nums) {
            if (t.find(n) == t.end()) t[n] = 0;
            t[n]++;
        }
        int l = 0, r = nums.size() - 1, pl = INT_MIN;
        vector<vector<int>> ans;
        while (l < r && nums[l] <= 0) {
            if (nums[l] == pl) {
                l++;
                continue;
            }
            int r = nums.size() - 1, pr = INT_MAX;
            while (l < r && nums[r] >= 0) {
                if (nums[r] == pr) {
                    r--;
                    continue;
                }
                int cnt = 1, tar = -(nums[l] + nums[r]);
                if (tar >= nums[l] && tar <= nums[r]) {
                    if (nums[l] == tar) cnt++;
                    if (nums[r] == tar) cnt++;
                    // cout << nums[l] << ", " << tar << ", " << nums[r] << ": " << cnt << endl;
                    if (t[tar] >= cnt) {
                        vector<int> v{ nums[l], tar, nums[r] };
                        ans.push_back(v);
                    } 
                }
                pr = nums[r--];
            }
            pl = nums[l++];
        }
        return ans;
    }
};