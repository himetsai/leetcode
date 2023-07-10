import java.lang.Math;

class Solution {
    public int reverse(int x) {
        int neg = 0;
        String s = String.valueOf(x);
        long result = 0;
        if (s.charAt(0) == '-') neg = 1;
        for (int i = s.length() - 1; i >= neg; i--) {
            result += (long) (Character.getNumericValue(s.charAt(i)) * Math.pow(10, i - neg));
            if (result > (long) Integer.MAX_VALUE || result < (long) Integer.MIN_VALUE) return 0;
        }
        result *= neg == 1 ? -1 : 1;
        return (int) result;
    }
}