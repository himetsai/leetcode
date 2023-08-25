class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size())
                nums[i] = nums.size() + 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) > nums.size()) continue;
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        int i = 0;
        while (i < nums.size() && nums[i] < 0) i++;
        return i + 1;
    }
};