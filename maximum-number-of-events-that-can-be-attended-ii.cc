class Solution {
public:
  int maxValue(vector<vector<int>>& events, int k) {
    vector<int> xs{0};
    for (auto e : events) {
      int S = e[0] - 1, E = e[1];
      xs.push_back(S); xs.push_back(E);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(events.begin(), events.end(), [](auto &a, auto &b) {
      return a[1] < b[1];
    });

    int N = xs.size(), j = 0, Z = events.size(), ans = 0;
    vector<vector<int>> dp(N + 1, vector<int>(k + 1));
    for (int i = 1; i <= N; i++) {
      for (int ki = 0; ki <= k; ki++) dp[i][ki] = dp[i - 1][ki];
      while (j < Z) {
        auto e = events[j];
        int S = e[0] - 1, E = e[1], V = e[2];

        int si = lower_bound(xs.begin(), xs.end(), S) - xs.begin();
        int ei = lower_bound(xs.begin(), xs.end(), E) - xs.begin();
        if (ei != i) break;

        for (int ki = 1; ki <= k; ki++) {
          dp[i][ki] = max(dp[i][ki], dp[si][ki - 1] + V);
          ans = max(ans, dp[i][ki]);
        }
        j++;
      }
    }
    return ans;
  }
};
