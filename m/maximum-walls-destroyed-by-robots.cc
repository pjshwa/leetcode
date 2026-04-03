#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    vector<pii> R; int N = robots.size(), M = walls.size();
    for (int i = 0; i < N; ++i) R.emplace_back(robots[i], distance[i]);
    sort(R.begin(), R.end());
    sort(walls.begin(), walls.end());

    vector<vector<int>> dp(N, vector<int>(2, 0));
    auto oob_w = [&](int x) { return x < 0 || x >= M; };
    auto get_lb = [&](int i, int p) {
      auto [r, d] = R[i];
      int maxj = lower_bound(walls.begin(), walls.end(), R[i].first) - walls.begin();
      if (maxj == M || walls[maxj] > r) --maxj;
      if (maxj == -1 || walls[maxj] < max(p + 1, r - d)) return pii{0, -1};

      int minj = maxj;
      while (!oob_w(minj)) {
        if (minj > 0 && walls[minj - 1] >= max(p + 1, r - d)) --minj;
        else break;
      }
      return pii{maxj - minj + 1, maxj};
    };
    auto get_rb = [&](int i, int p) {
      auto [r, d] = R[i];
      int minj = lower_bound(walls.begin(), walls.end(), R[i].first) - walls.begin();
      if (minj == M || walls[minj] > min(r + d, p - 1)) return pii{0, M};

      int maxj = minj;
      while (!oob_w(maxj)) {
        if (maxj < M - 1 && walls[maxj + 1] <= min(p - 1, r + d)) ++maxj;
        else break;
      }
      return pii{maxj - minj + 1, maxj};
    };
    dp[0][0] = get_lb(0, -INF).first;
    dp[0][1] = get_rb(0, N == 1 ? INF : R[1].first).first;

    for (int i = 1; i < N; ++i) {
      auto [r, d] = R[i];

      {
        auto [len, maxj] = get_lb(i, R[i - 1].first);
        if (len == 0) dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        else {
          dp[i][0] = dp[i - 1][0] + len;
          int minj = maxj - len + 1;
          auto [plen, pmaxj] = get_rb(i - 1, r);
          if (pmaxj >= minj) dp[i][0] = max(dp[i][0], dp[i - 1][1] + maxj - pmaxj);
          else dp[i][0] = max(dp[i][0], dp[i - 1][1] + len);
        }
      }
      {
        auto [len, _] = get_rb(i, i == N - 1 ? INF : R[i + 1].first);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + len;
      }
    }
    return max(dp[N - 1][0], dp[N - 1][1]);
  }
};
