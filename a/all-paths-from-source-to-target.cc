class Solution {
  vector<vector<int>> ans;
  vector<int> cur;
  int n;

  void dfs(int v, vector<vector<int>>& graph) {
    cur.push_back(v);
    if (v == n - 1) ans.push_back(cur);
    else for (int u : graph[v]) {
      dfs(u, graph);
    }
    cur.pop_back();
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    n = graph.size();
    dfs(0, graph);
    return ans;
  }
};
