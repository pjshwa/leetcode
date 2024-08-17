using ll = long long;

class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    int N = points.size(), M = points[0].size();
    vector<vector<ll>> dp(N, vector<ll>(M));

    using T = pair<ll, int>;
    priority_queue<T> pq_l, pq_r;
    for (int j = 0; j < M; ++j) {
      dp[0][j] = points[0][j];
      pq_r.push({dp[0][j] - j, j});
    }

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        while (!pq_r.empty() && pq_r.top().second < j) pq_r.pop();
        pq_l.push({dp[i - 1][j] + j, j});

        int lj = pq_l.top().second, rj = pq_r.top().second;
        dp[i][j] = points[i][j] + max(
          dp[i - 1][lj] - abs(lj - j),
          dp[i - 1][rj] - abs(rj - j)
        );
      }

      while (!pq_l.empty()) pq_l.pop();
      while (!pq_r.empty()) pq_r.pop();
      for (int j = 0; j < M; ++j) pq_r.push({dp[i][j] - j, j});
    }

    ll ans = 0;
    for (int j = 0; j < M; ++j) ans = max(ans, dp[N - 1][j]);
    return ans;
  }
};
