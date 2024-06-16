class Solution {
  bool vis[1000];
  vector<vector<int>> g;

  void dfs(int v) {
    vis[v] = 1;
    for (int u : g[v]) {
      if (!vis[u]) dfs(u);
    }
  }

public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    g = rooms;
    memset(vis, 0, sizeof(vis));
    dfs(0);
    for (int i = 0; i < rooms.size(); i++) {
      if (!vis[i]) return false;
    }
    return true;
  }
};
