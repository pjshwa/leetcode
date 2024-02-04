class Solution {
public:
  int numberOfPairs(vector<vector<int>>& points) {
    int N = points.size(), ans = 0;

    vector<int> xs, ys;
    for (auto& v : points) {
      xs.push_back(v[0]);
      ys.push_back(v[1]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    map<int, int> inv_x, inv_y;
    for (int i = 1; i <= N; ++i) {
      inv_x[xs[i - 1]] = i;
      inv_y[ys[i - 1]] = i;
    }

    vector<pair<int, int>> points_i;
    for (auto& v : points) {
      int x = v[0], y = v[1];
      points_i.push_back({inv_x[x], inv_y[y]});
    }

    vector<vector<int>> P(N + 10, vector<int>(N + 10, 0));
    for (auto& [x, y] : points_i) P[x][y] += 1;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) {
      P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }

    for (auto& [x1, y1] : points_i) for (auto& [x2, y2] : points_i) {
      if (x1 == x2 && y1 == y2) continue;
      if (x2 < x1 || y2 > y1) continue;

      int minx = x1, maxx = x2;
      int miny = y2, maxy = y1;

      int cnt = P[maxx][maxy] - P[minx - 1][maxy] - P[maxx][miny - 1] + P[minx - 1][miny - 1];
      // cout << "minx: " << minx << " maxx: " << maxx << " miny: " << miny << " maxy: " << maxy << " cnt: " << cnt << "\n";
      if (cnt == 2) ++ans;
    }
    return ans;
  }
};
