using ll = long long;
using matrix = vector<vector<ll>>;
const int V = 26, MOD = 1e9 + 7;

matrix operator * (const matrix &a, const matrix &b) {
  int n = a.size();
  matrix c(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    }
  }
  return c;
}

class Solution {
public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    matrix a = matrix(V, vector<ll>(V, 0));
    matrix ans = matrix(V, vector<ll>(V, 0));
    for (int i = 0; i < V; ++i) {
      ans[i][i] = 1;
      for (int j = 0; j < nums[i]; ++j) a[(i + j + 1) % V][i] = 1;
    }

    while (t) {
      if (t & 1) ans = ans * a;
      a = a * a;
      t >>= 1;
    }

    ll ret = 0;
    for (char c : s) {
      for (int i = 0; i < V; ++i) ret = (ret + ans[i][c - 'a']) % MOD;
    }
    return ret;
  }
};
