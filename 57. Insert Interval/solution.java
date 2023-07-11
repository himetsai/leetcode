class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int start = intervals.length;
        int end = intervals.length;
        int[] ni = {newInterval[0], newInterval[1]};
        int overlap = 1;
        if (intervals.length == 0) return new int[][]{ni};
        for (int i = 0; i < intervals.length; i++) {
            if (intervals[i][0] > newInterval[0]) {
                start = i;
                break;
            }
            if (intervals[i][1] >= newInterval[0]) {
                start = i;
                ni[0] = intervals[i][0];
                break;
            }
        }
        for (int i = 0; i < intervals.length; i++) {
            if (intervals[i][0] > newInterval[1]) {
                end = i;
                break;
            }
            if (intervals[i][1] >= newInterval[1]) {
                overlap = 0;
                end = i;
                ni[1] = intervals[i][1];
                break;
            }
        }
        int[][] result = new int[intervals.length + overlap - end + start][2];
        int index = 0;
        for (int i = 0; i < intervals.length; i++) {
            if (i == start) result[index++] = ni;
            if (i < start || i > end - overlap) result[index++] = intervals[i];
        }
        if (start == intervals.length) result[start] = ni;
        return result;
    }
}