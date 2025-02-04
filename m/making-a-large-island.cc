const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<int> parent(N * N), usz(N * N, 1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };

    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (grid[i][j] == 0) continue;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N || grid[ni][nj] == 0) continue;
        Union(i * N + j, ni * N + nj);
      }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (grid[i][j] == 1) ans = max(ans, usz[Find(i * N + j)]);
      else {
        set<int> groups_adj;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni < 0 || ni >= N || nj < 0 || nj >= N || grid[ni][nj] == 0) continue;
          groups_adj.insert(Find(ni * N + nj));
        }

        int cur = 1;
        for (int group : groups_adj) cur += usz[group];
        ans = max(ans, cur);
      }
    }
    return ans;
  }
};
