using ll = long long;
const int MAX = 1000, MOD = 1e9 + 7;

class Solution {
  ll t[MAX][26], d[MAX + 1][MAX + 1];
  int O[MAX], n, z;

  ll r(int i, int j) {
    if (j == z) return 1;
    if (i == n) return 0;
    if (d[i][j] != -1) return d[i][j];

    ll ret = r(i + 1, j);
    ret = (ret + r(i + 1, j + 1) * t[i][O[j]]) % MOD;
    return d[i][j] = ret;
  }

public:
  int numWays(vector<string>& words, string target) {
    z = target.size();
    for (int i = 0; i < z; ++i) O[i] = target[i] - 'a';

    n = words[0].size();
    for (auto& word : words) {
      for (int i = 0; i < n; ++i) t[i][word[i] - 'a']++;
    }

    memset(d, -1, sizeof(d));
    return r(0, 0);
  }
};
