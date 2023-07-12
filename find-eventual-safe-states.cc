class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int N = graph.size();

    vector<int> radj[N]; int indegree[N];
    for (int i = 0; i < N; i++) {
      indegree[i] = graph[i].size();
      for (auto e : graph[i]) radj[e].push_back(i);
    }

    vector<int> ans; queue<int> q;
    for (int i = 0; i < N; i++) if (!indegree[i]) q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      ans.push_back(u);
      for (auto v : radj[u]) if (--indegree[v] == 0) q.push(v);
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};
