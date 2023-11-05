const int MAXV = 1e5;

class Solution {
public:
  int oddEvenJumps(vector<int>& arr) {
    int N = arr.size();
    set<int> pre; int inv[MAXV];
    pre.insert(arr[N - 1]); inv[arr[N - 1]] = N - 1;
    vector<int> adj_up(N, -1), adj_down(N, -1);

    for (int i = N - 2; i >= 0; --i) {
      auto it_up = pre.lower_bound(arr[i]);
      if (it_up != pre.end()) {
        int j = inv[*it_up];
        adj_up[i] = j;
      }

      auto it_down = pre.upper_bound(arr[i]);
      if (it_down != pre.begin()) {
        --it_down;
        int j = inv[*it_down];
        adj_down[i] = j;
      }

      pre.insert(arr[i]); inv[arr[i]] = i;
    }

    int dp[N][2]; memset(dp, -1, sizeof dp);
    function<int(int, int)> dfs = [&](int i, int p) {
      if (i == -1) return 0;
      if (i == N - 1) return 1;
      if (dp[i][p] != -1) return dp[i][p];

      int ret = 0;
      if (p) ret |= dfs(adj_up[i], 0);
      else ret |= dfs(adj_down[i], 1);
      return dp[i][p] = ret;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) ans += dfs(i, 1);
    return ans;
  }
};
