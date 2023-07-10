class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> l = new ArrayList<Integer>(matrix.length * matrix[0].length);
        int round = 0;
        while (matrix.length > round * 2 && matrix[0].length > round * 2) {
            int r = round;
            int c = round;
            l.add(matrix[r][c]);
            while (++r < matrix[0].length - round) {
                l.add(matrix[c][r]);
            }
            r--;
            while (++c < matrix.length - round) {
                l.add(matrix[c][r]);
            }
            c--;
            if (c == round || r == round) break;
            while (--r >= round) {
                l.add(matrix[c][r]);
            }
            r++;
            while (--c > round) {
                l.add(matrix[c][r]);
            }
            round++;
        }
        return l;
    }
}