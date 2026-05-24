#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxJumps(vector<int>& arr, int d) {
    int N = arr.size();
    vector<int> adj[N];
    stack<pair<int, int>> s;
    for (int i = 0; i < N; ++i) {
      while (!s.empty() && s.top().first < arr[i]) {
        auto [h, j] = s.top(); s.pop();
        if (i - j <= d) adj[i].push_back(j);
      }
      s.emplace(arr[i], i);
    }
    while (!s.empty()) s.pop();
    for (int i = N - 1; i >= 0; --i) {
      while (!s.empty() && s.top().first < arr[i]) {
        auto [h, j] = s.top(); s.pop();
        if (j - i <= d) adj[i].push_back(j);
      }
      s.emplace(arr[i], i);
    }

    vector<int> dp(N, -1);
    function<int(int)> dfs = [&](int u) {
      if (dp[u] != -1) return dp[u];
      int res = 1;
      for (int v : adj[u]) res = max(res, 1 + dfs(v));
      return dp[u] = res;
    };
    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dfs(i));
    return ans;
  }
};
