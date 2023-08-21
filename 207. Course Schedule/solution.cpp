class Solution {
public:
    int count = 0;

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& indegree, int ind) {
        if (visited[ind] || indegree[ind] != 0) return;
        visited[ind] = true;
        count++;
        for (int v : graph[ind]) {
            indegree[v]--;
            dfs(graph, visited, indegree, v);
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        vector<bool> visited(numCourses, false);
        
        for (auto v : prerequisites) {
            graph[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }

        for (int i = 0; i < numCourses; i++)
            dfs(graph, visited, indegree, i);
        cout << count << endl;
        return count == numCourses;
    }
};