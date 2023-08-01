class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < nums.size() && l < r) {
            if (nums[l] == 0) l++;
            else if (nums[r] == 0)
                swap(nums[l], nums[r--]);
            else r--;
        }
        l = 0;
        r = nums.size() - 1;
        while (r >= 0 && l < r) {
            if (nums[r] == 2) r--;
            else if (nums[l] == 2)
                swap(nums[l++], nums[r]);
            else l++;
        }
    }
};