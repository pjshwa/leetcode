const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

class Solution {
public:
  int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    int parent[n * m];
    iota(parent, parent + n * m, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) continue;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 1) continue;
        Union(i * m + j, x * m + y);
      }
    }

    auto is_border = [&](int x, int y) {
      return x == 0 || x == n - 1 || y == 0 || y == m - 1;
    };

    set<int> groups;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) groups.insert(Find(i * m + j));
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0 && is_border(i, j)) {
        groups.erase(Find(i * m + j));
      }
    }
    return groups.size();
  }
};
