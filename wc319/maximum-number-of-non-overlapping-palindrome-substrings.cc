class Solution {
  bool seq_p[2001][2001];
  int d[2001];

public:
  int maxPalindromes(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      seq_p[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
      seq_p[i][i + 1] = s[i] == s[i + 1];
    }
    for (int diff = 2; diff < n; diff++) {
      for (int i = 0; i < n - diff; i++) {
        int j = i + diff;
        seq_p[i][j] = (s[i] == s[j] && seq_p[i + 1][j - 1]);
      }
    }

    memset(d, 0, sizeof(d));

    for (int i = 0; i < n; i++) {
      bool pf = false;
      for (int j = i - k + 1; j >= 0; j--) {
        if (pf) d[i] = max(d[i], d[j] + 1);
        if (seq_p[j][i]) pf = true;
      }
      if (pf) d[i] = max(d[i], 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, d[i]);
    }
    return ans;
  }
};
