class Solution {
public:
  int minimumSum(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> P(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      P[i][j] = grid[i][j];
      if (i > 0) P[i][j] += P[i - 1][j];
      if (j > 0) P[i][j] += P[i][j - 1];
      if (i > 0 && j > 0) P[i][j] -= P[i - 1][j - 1];
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
      int ret = P[x2][y2];
      if (x1 > 0) ret -= P[x1 - 1][y2];
      if (y1 > 0) ret -= P[x2][y1 - 1];
      if (x1 > 0 && y1 > 0) ret += P[x1 - 1][y1 - 1];
      return ret;
    };

    auto get_area = [&](int x1, int y1, int x2, int y2) {
      int l = x1, r = x2, u = y1, d = y2;
      while (l <= x2 && get(l, y1, l, y2) == 0) ++l;
      while (r >= x1 && get(r, y1, r, y2) == 0) --r;
      while (u <= y2 && get(x1, u, x2, u) == 0) ++u;
      while (d >= y1 && get(x1, d, x2, d) == 0) --d;
      if (l > r || u > d) return 1;
      return (r - l + 1) * (d - u + 1);
    };

    int ans = N * M;
    for (int h1 = 1; h1 < N; ++h1) for (int h2 = h1 + 1; h2 < N; ++h2) {
      int area = get_area(0, 0, h1 - 1, M - 1) +
                 get_area(h1, 0, h2 - 1, M - 1) +
                 get_area(h2, 0, N - 1, M - 1);
      ans = min(ans, area);
    }
    for (int w1 = 1; w1 < M; ++w1) for (int w2 = w1 + 1; w2 < M; ++w2) {
      int area = get_area(0, 0, N - 1, w1 - 1) +
                 get_area(0, w1, N - 1, w2 - 1) +
                 get_area(0, w2, N - 1, M - 1);
      ans = min(ans, area);
    }
    for (int h = 1; h < N; ++h) for (int w = 1; w < M; ++w) {
      int area1 = get_area(0, 0, h - 1, M - 1) +
                  get_area(h, 0, N - 1, w - 1) +
                  get_area(h, w, N - 1, M - 1);
      int area2 = get_area(0, 0, h - 1, w - 1) +
                  get_area(0, w, h - 1, M - 1) +
                  get_area(h, 0, N - 1, M - 1);
      int area3 = get_area(0, 0, N - 1, w - 1) +
                  get_area(0, w, h - 1, M - 1) +
                  get_area(h, w, N - 1, M - 1);
      int area4 = get_area(0, 0, h - 1, w - 1) +
                  get_area(h, 0, N - 1, w - 1) +
                  get_area(0, w, N - 1, M - 1);
      ans = min({ans, area1, area2, area3, area4});
    }
    return ans;
  }
};
