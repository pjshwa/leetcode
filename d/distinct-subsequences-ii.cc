#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  int distinctSubseqII(string s) {
    int N = s.size(), ans = 0, MOD = 1e9 + 7;
    vector<int> dp(N, 0), V(26, 0);
    for (int i = 0; i < N; ++i) {
      int c = s[i] - 'a';
      if (V[c] == 0) dp[i] = 1, V[c] = 1;
      for (int j = i - 1; j >= 0; --j) {
        dp[i] = (dp[i] + dp[j]) % MOD;
        if (s[i] == s[j]) break;
      }
      ans = (ans + dp[i]) % MOD;
    }
    return ans;
  }
};
