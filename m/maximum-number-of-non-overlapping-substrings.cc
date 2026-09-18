#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> maxNumOfSubstrings(string s) {
    int N = s.size(), c_maxi[26], c_mini[26];
    memset(c_mini, -1, sizeof(c_mini));
    vector<vector<int>> P(26, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
      int c = s[i - 1] - 'a';
      if (c_mini[c] == -1) c_mini[c] = i;
      c_maxi[c] = i;
      for (int j = 0; j < 26; ++j) P[j][i] = P[j][i - 1] + (j == c);
    }

    vector<int> dp(N + 1, 0), nxt(N + 1, -1);
    for (int i = 1; i <= N; ++i) {
      dp[i] = dp[i - 1];
      int c = s[i - 1] - 'a';
      if (c_maxi[c] != i) continue;

      int F[26]{}, j;
      for (j = c_maxi[c]; j >= 1; --j) {
        int c2 = s[j - 1] - 'a', ok = 1;
        ++F[c2];
        for (int l = 0; l < 26; ++l) {
          if (F[l] > 0 && F[l] != P[l][N]) ok = 0;
        }
        if (ok) break;
      }
      if (j && dp[i] < dp[j - 1] + 1) {
        dp[i] = dp[j - 1] + 1;
        nxt[i] = j - 1;
      }
    }

    // cout << dp[N] << endl;
    vector<string> ans;
    for (int i = N; i >= 1; --i) {
      if (nxt[i] == -1) continue;
      ans.push_back(s.substr(nxt[i], i - nxt[i]));
      i = nxt[i] + 1;
    }
    return ans;
  }
};
