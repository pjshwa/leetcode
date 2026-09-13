#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {

    vector<tuple<int, int, int, int>> V; int N = intervals.size();
    for (int i = 0; i < N; ++i) {
      int s = intervals[i][0], e = intervals[i][1], w = intervals[i][2];
      V.push_back({e, s, w, i});
    }
    sort(V.begin(), V.end());

    // dp[t][i] = max weight of items til index i, taken t items
    vector<vector<ll>> dp(5, vector<ll>(N, 0));
    vector<vector<vector<int>>> A(5, vector<vector<int>>(N));
    for (int t = 0; t < 5; ++t) for (int i = 0; i < N; ++i) {
      if (i > 0) {
        dp[t][i] = dp[t][i - 1];
        A[t][i] = A[t][i - 1];
      }
      auto [e, s, w, idx] = V[i];
      if (t > 0) {
        int j = lower_bound(V.begin(), V.end(), make_tuple(s, 0, 0, 0)) - V.begin() - 1;
        ll val = w + (j >= 0 ? dp[t - 1][j] : 0);
        vector<int> candidate = j >= 0 ? A[t - 1][j] : vector<int>{};
        candidate.push_back(idx);
        sort(candidate.begin(), candidate.end());

        if (val > dp[t][i] || (val == dp[t][i] && candidate < A[t][i])) {
          dp[t][i] = val;
          A[t][i] = candidate;
        }
      }
    }
    return A[4][N - 1];
  }
};
