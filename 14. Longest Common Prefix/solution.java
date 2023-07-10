class Solution {
    public String longestCommonPrefix(String[] strs) {
        boolean check = true;
        int cnt = 0;
        while (check) {
            if (cnt >= strs[0].length()) break;
            char cur = strs[0].charAt(cnt);
            for (String s : strs) {
                if (cnt >= s.length() || s.charAt(cnt) != cur) check = false;
            }
            cnt += (check) ? 1 : 0;
        }
        return strs[0].substring(0, cnt);
    }
}