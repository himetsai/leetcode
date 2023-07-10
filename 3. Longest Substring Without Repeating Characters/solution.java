import java.util.HashMap; 
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result = 0, prev = 0;
        HashMap<Character, Integer> ht = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            Integer c = ht.get(s.charAt(i));
            if (c != null) {
                if (i - prev > result) result = i - prev;
                prev = c + 1; 
                ht.clear();
                i = c;
            }
            else ht.put(s.charAt(i), i);
        }
        if (s.length() - prev > result) result = s.length() - prev;
        return result;
    }
}