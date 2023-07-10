class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length; i++) {
            int temp = target - nums[i];
            int l = (i == 0) ? 1 : 0;
            int r = (i == nums.length - 1) ? i - 1 : nums.length - 1;
            int sum = nums[l] + nums[r];
            while (l < r) {
                if (Math.abs(nums[l] + nums[r] - temp) < Math.abs(sum - temp)) {
                    sum = nums[l] + nums[r];
                }
                if (nums[l] + nums[r] == temp) return target;
                if (nums[l] + nums[r] > temp) r--;
                else l++;
                if (r == i) r--;
                if (l == i) l++;
            }
            if (Math.abs(sum - temp) < Math.abs(closest - target)) closest = sum + nums[i];
        }
        return closest;
    }
}