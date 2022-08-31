const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

class Solution {
  bool vis1[200][200], vis2[200][200];
  vector<vector<int>> heights;
  int n, m;

  void dfs(int i, int j, bool vis[][200]) {
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) continue;
      if (heights[x][y] >= heights[i][j]) dfs(x, y, vis);
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size(), m = heights[0].size();
    this->heights = heights;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    for (int i = 0; i < n; i++) {
      dfs(i, 0, vis1);
      dfs(i, m - 1, vis2);
    }
    for (int j = 0; j < m; j++) {
      dfs(0, j, vis1);
      dfs(n - 1, j, vis2);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (vis1[i][j] && vis2[i][j]) ans.push_back({i, j});
    }
    return ans;
  }
};
