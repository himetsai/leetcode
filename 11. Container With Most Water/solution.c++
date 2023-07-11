class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ms = min(height[l], height[r]) * (r - l);
        while (l < r) {
            if (height[l] < height[r]) {
                while (min(height[l], height[r]) * (r - l) <= ms && height[r] >= height[l] && l < r)
                    l++;
            }
            else {
                while (min(height[l], height[r]) * (r - l) <= ms && height[l] >= height[r] && l < r)
                    r--;
            }
            ms = max(ms, min(height[l], height[r]) * (r - l));
        }
        return ms;
    }
};