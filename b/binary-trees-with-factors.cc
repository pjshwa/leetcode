using ll = long long;
const int MAX = 1000, MOD = 1e9 + 7;

class Solution {
  vector<int> arr; int N;
  ll dp[MAX]; map<int, int> inv;

  ll as_root(int i) {
    if (dp[i] != -1) return dp[i];

    ll ret = 0;
    for (int j = 0; j < i; ++j) {
      if (arr[i] % arr[j]) continue;

      int r = arr[i] / arr[j];
      if (!inv.count(r)) continue;

      ret = (ret + as_root(j) * as_root(inv[r])) % MOD;
    }
    return dp[i] = ret + 1;
  }

public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    this->arr = arr; N = arr.size();
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < N; ++i) {
      inv[arr[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans = (ans + as_root(i)) % MOD;
    }
    return ans;
  }
};
