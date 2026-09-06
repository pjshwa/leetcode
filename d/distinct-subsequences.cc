#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = INT_MAX;

class Solution {
public:
  int numDistinct(string s, string t) {
    int Sz = s.size(), Tz = t.size();
    vector<vector<ll>> dp(Sz + 1, vector<ll>(Tz + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= Sz; ++i) for (int j = 0; j <= Tz; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j > 0 && s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
      if (dp[i][j] > INF) dp[i][j] = INF;
    }
    return dp[Sz][Tz];
  }
};
