using ll = long long;
const ll MAXN = 100, INF = 1e18;

class Solution {
public:
  ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });
    int N = robot.size(), M = factory.size();
    vector<vector<ll>> dp(M, vector<ll>(N, -1));

    function<ll(int, int)> rec = [&](int i, int t) {
      if (t == N) return 0LL;
      if (i == M) return INF;
      if (dp[i][t] != -1) return dp[i][t];

      ll free = N - t, ret = INF, cap = factory[i][1], cost = 0;
      for (int take = 0; take <= min(cap, free); ++take) {
        ret = min(ret, cost + rec(i + 1, t + take));
        if (t + take == N) break;
        cost += abs(robot[t + take] - factory[i][0]);
      }
      return dp[i][t] = ret;
    };
    return rec(0, 0);
  }
};
