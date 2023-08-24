class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set;
        for (int n : nums) 
            set.insert(n);
        for (int n : nums) {
            if (set.find(n - 1) == set.end()) {
                int curr = n;
                while (set.find(++curr) != set.end());
                ans = max(ans, curr - n);
            }
        }
        return ans;
    }
};