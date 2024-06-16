const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int N = grid.size();

    int parent[N * N];
    iota(parent, parent + N * N, 0);

    function<int(int)> Find = [&](int x) {
      return parent[x] == x ? x : parent[x] = Find(parent[x]);
    };
    function<void(int, int)> Union = [&](int x, int y) {
      parent[Find(x)] = Find(y);
    };

    int inv[N * N];
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      int id = i * N + j;
      inv[grid[i][j]] = id;
    }

    for (int t = 0; t < N * N; ++t) {
      int i = inv[t] / N, j = inv[t] % N;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N || grid[ni][nj] > t) continue;

        Union(inv[t], ni * N + nj);
      }

      if (Find(0) == Find(N * N - 1)) return t;
    }

    return -1;
  }
};
