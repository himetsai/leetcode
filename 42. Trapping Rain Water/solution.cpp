class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < height.size(); i++) {
            if (!st.empty() && height[i] >= height[st.top()]) {
                int block = 0;
                int curr;
                while (!st.empty() && height[i] >= height[st.top()]) {
                    curr = st.top();
                    st.pop();
                    if (!st.empty()) {
                        block += height[curr] * (curr - st.top());
                    }
                }
                int l = st.empty() ? curr : st.top();
                ans += min(height[l], height[i]) * (i - l - 1) - block;
            }
            st.push(i);
        }

        return ans;
    }
};