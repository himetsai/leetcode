class Solution {
    public boolean canJump(int[] nums) {
        int[] r = new int[nums.length];
        r[0] = 1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (r[i] == 1) {
                for (int j = 1; j <= nums[i]; j++) {
                    if (i + j == nums.length - 1) return true;
                    if (r[i + j] != 1) r[i + j] = 1;
                }
            }
        }
        return (r[nums.length - 1] == 1) ? true : false;
    }
}