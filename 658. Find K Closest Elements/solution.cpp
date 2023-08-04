class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        int m;
        vector<int> ans;
        while (l + 1 < r) {
            m = (l + r) / 2;
            if (arr[m] > x) r = m;
            else l = m;
        }
        m = (abs(arr[l] - x) <= abs(arr[r] - x)) ? l : r;
        l = m, r = m;
        while (r - l + 1 < k) {
            if (r >= arr.size() - 1) l--;
            else if (l <= 0) r++;
            else if (abs(arr[l-1] - x) <= abs(arr[r+1] - x)) l--;
            else r++;
        }
        for (int i = l; i <= r; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};