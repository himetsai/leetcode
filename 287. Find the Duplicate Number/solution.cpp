class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> s(nums.size(), false);
        for (int n : nums) {
            if (s[n]) return n;
            s[n] = true;
        }
        return -1;
    }
};