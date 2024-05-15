const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int N = grid.size();

    // safeness factor
    vector<vector<int>> D(N, vector<int>(N, INF));
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) continue;
      D[i][j] = 0; Q.push({i, j});
    }

    while (!Q.empty()) {
      auto [i, j] = Q.front(); Q.pop();
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
        if (D[ni][nj] != INF) continue;
        D[ni][nj] = D[i][j] + 1;
        Q.push({ni, nj});
      }
    }

    auto reachable = [&](int x) {
      if (D[0][0] < x) return false;

      vector<vector<int>> vis(N, vector<int>(N, 0));
      Q.push({0, 0}); vis[0][0] = 1;
      while (!Q.empty()) {
        auto [i, j] = Q.front(); Q.pop();
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
          if (D[ni][nj] < x || vis[ni][nj]) continue;
          vis[ni][nj] = 1; Q.push({ni, nj});
        }
      }
      return vis[N - 1][N - 1] == 1;
    };

    int l = 0, r = 2 * N;
    while (l < r) {
      int mid = (l + r) / 2;
      if (reachable(mid)) l = mid + 1;
      else r = mid;
    }
    return l - 1;
  }
};
