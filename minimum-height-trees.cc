const int MAX = 2e4;
class Solution {
  int indegree[MAX];
  vector<int> graph[MAX];
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    for (auto& e : edges) {
      int u = e[0], v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
      indegree[u]++;
      indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 1) q.push(i);
    }

    while (n > 2) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
          indegree[v]--;
          if (indegree[v] == 1) q.push(v);
        }
      }
      n -= size;
    }

    vector<int> ans;
    while (!q.empty()) {
      ans.push_back(q.front());
      q.pop();
    }

    return ans;
  }
};
