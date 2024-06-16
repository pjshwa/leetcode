class Solution {
  int color[100];

  bool dfs(int v, int c, vector<vector<int>>& graph) {
    color[v] = c;

    for (auto d : graph[v]) {
      if (color[d] == -1) {
        if (!dfs(d, c ^ 1, graph)) return false;
      }
      else if (color[v] == color[d]) return false;
    }

    return true;
  }

public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    memset(color, -1, sizeof color);
    
    for (int i = 0; i < n; i++) {
      if (color[i] == -1) {
        if (!dfs(i, 0, graph)) return false;
      }
    }

    return true;
  }
};
