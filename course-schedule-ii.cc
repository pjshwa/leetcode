class Solution {
  vector<int> graph[2001];
  int indegree[2001];
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    memset(indegree, 0, sizeof(indegree));
    for (auto& u : prerequisites) {
      graph[u[1]].push_back(u[0]);
      indegree[u[0]]++;
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (!indegree[i]) q.push(i);
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ans.push_back(u);

      for (int dst : graph[u]) {
        indegree[dst]--;
        if (!indegree[dst]) q.push(dst);
      }
    }

    if (ans.size() != numCourses) return {};
    return ans;
  }
};
