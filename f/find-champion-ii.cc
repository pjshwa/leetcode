class Solution {
public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> indegree(n, 0);
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      ++indegree[v];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) if (!indegree[i]) q.push(i);
    return q.size() == 1 ? q.front() : -1;
  }
};
