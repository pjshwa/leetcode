using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfArrays(string s, int k) {
    int n = s.size();

    int d[n + 1];
    memset(d, 0, sizeof(d)); d[0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= max(1, i - 10); j--) {
        if (s[j - 1] == '0') continue;

        long long num = stoll(s.substr(j - 1, i - j + 1));
        if (num > k) break;

        d[i] = (d[i] + d[j - 1]) % MOD;
      }
    }
    return d[n];
  }
};
