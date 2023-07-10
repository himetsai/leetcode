import java.util.HashMap; 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++) {
            Integer temp = map.get(target - nums[i]);
            if (temp != null) {
                result[0] = temp;
                result[1] = i;
            }
            map.put(nums[i], i);
        }
        return result;
    }
}