class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color = vector<int>(graph.size());
        set<int> unvisited;
        for (int i = 0; i < graph.size(); i++)
            unvisited.insert(i);
        stack<int> st;
        while (!unvisited.empty()) {
            int curr = *unvisited.begin();
            unvisited.erase(curr);
            color[curr] = 0;
            st.push(curr);
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                for (int n : graph[node]) {
                    if (unvisited.find(n) == unvisited.end()) {
                        if (color[node] == color[n]) return false;
                    }
                    else {
                        st.push(n);
                        unvisited.erase(n);
                        color[n] = (color[node] + 1) % 2;
                    }
                }
            }
        }
        return true;
    }
};