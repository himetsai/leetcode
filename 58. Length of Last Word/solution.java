class Solution {
    public int lengthOfLastWord(String s) {
        int t = s.length() - 1;
        int x = 0, y = -1;
        while(t >= 0) {
            if (s.charAt(t) != ' ') {
                x = t;
                break;
            }
            t--;
        }
        while(t >= 0) {
            if (s.charAt(t) == ' ') {
                y = t;
                break;
            }
            t--;
        }
        return x - y;
    }
}