class Solution {
    class ArrayComparator implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            if (a[0] != b[0]) return a[0] - b[0];
            else return a[1] - b[1];
        }
    }

    ArrayList<int[]> temp = new ArrayList();
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new ArrayComparator());
        for (int i = 0; i < intervals.length; i++) {
            int[] next = {intervals[i][0], intervals[i][1]};
            while (i < intervals.length) {
                if (next[1] < intervals[i][0]) {
                    next[1] = Math.max(next[1], intervals[i - 1][1]);
                    i--;
                    break;
                }
                next[1] = Math.max(next[1], intervals[i][1]);
                i++;
            }
            temp.add(next);
        }
        int[][] result = new int[temp.size()][2];
        for (int i = 0; i < temp.size(); i++) {
            result[i] = temp.get(i);
        }
        return result;
    }
}