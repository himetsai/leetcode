class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int, int>> win;
        for (int i = 0; i < k; i++) {
            while (!win.empty() && win.back().first <= nums[i])
                win.pop_back();
            win.push_back(make_pair(nums[i], i));
        }
        ans.push_back(win.front().first);
        for (int i = k; i < nums.size(); i++) {
            if (win.front().second == i - k) win.pop_front();
            while (!win.empty() && win.back().first <= nums[i])
                win.pop_back();
            win.push_back(make_pair(nums[i], i));
            ans.push_back(win.front().first);
        }
        return ans;
    }
};