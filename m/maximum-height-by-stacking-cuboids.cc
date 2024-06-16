class Solution {
public:
  int maxHeight(vector<vector<int>>& cuboids) {
    int N = cuboids.size();

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < N; ++i) {
      int p[3] = {cuboids[i][0], cuboids[i][1], cuboids[i][2]};
      for (int it = 0; it < 6; ++it) {
        v.emplace_back(p[0], p[1], p[2]);
        next_permutation(p, p + 3);
      }
    }
    sort(v.begin(), v.end());

    int W[N][6], H[N][6], D[N][6];
    for (int i = 0; i < N; ++i) {
      for (int it = 0; it < 6; ++it) {
        W[i][it] = get<0>(v[i * 6 + it]);
        H[i][it] = get<1>(v[i * 6 + it]);
        D[i][it] = get<2>(v[i * 6 + it]);
      }
    }

    int dp[N][6]; memset(dp, -1, sizeof dp);
    function<int(int, int)> dfs = [&](int i, int it) {
      if (dp[i][it] != -1) return dp[i][it];

      int ret = 0;
      for (int j = i + 1; j < N; ++j) for (int nit = 0; nit < 6; ++nit) {
        if (W[i][it] <= W[j][nit] && H[i][it] <= H[j][nit] && D[i][it] <= D[j][nit])
          ret = max(ret, dfs(j, nit) + D[i][it]);
      }
      return dp[i][it] = ret;
    };

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int it = 0; it < 6; ++it) {
      ans = max(ans, dfs(i, it));
    }
    return ans;
  }
};
