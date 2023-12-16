class Solution {
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    vector<int> xs, ys;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0) continue;
      xs.push_back(i); ys.push_back(j);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int x = xs[xs.size() / 2], y = ys[ys.size() / 2];
    int ans = 0;
    for (int i = 0; i < xs.size(); ++i) ans += abs(xs[i] - x);
    for (int i = 0; i < ys.size(); ++i) ans += abs(ys[i] - y);
    return ans;
  }
};
