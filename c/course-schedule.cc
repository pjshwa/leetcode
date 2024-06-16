class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int N = numCourses;
    vector<int> adj[N]; int indegree[N];

    memset(indegree, 0, sizeof indegree);
    for (auto &p : prerequisites) {
      adj[p[1]].push_back(p[0]);
      indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) if (indegree[i] == 0) q.push(i);

    for (int i = 0; i < N; i++) {
      if (q.empty()) return false;

      int u = q.front(); q.pop();
      for (int v : adj[u]) {
        if (--indegree[v] == 0) q.push(v);
      }
    }
    return true;
  }
};
