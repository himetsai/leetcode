class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] arr = new int[(nums1.length + nums2.length) / 2 + 1];
        int p1 = 0, p2 = 0, i = arr.length - 1;
        while (p1 < nums1.length && p2 < nums2.length && i >= 0) {
            if (nums1[p1] < nums2[p2]) arr[i] = nums1[p1++];
            else arr[i] = nums2[p2++];
            i--;
        }
        if (p1 == nums1.length) {
            while (i >= 0) arr[i--] = nums2[p2++];
        }
        else if (p2 == nums2.length) {
            while (i >= 0) arr[i--] = nums1[p1++];
        }
        for (int j : arr) System.out.println(j);
        if ((nums1.length + nums2.length) % 2 == 1) return (double) arr[0];
        return ((double) arr[0] + (double) arr[1]) / 2;
    }
}