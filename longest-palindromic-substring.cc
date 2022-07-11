class Solution {
  bool p[1000][1000];
public:
  string longestPalindrome(string s) {
    int n = s.size();

    int si, ei;
    for (int diff = 0; diff < n; diff++) {
      for (int i = 0; i < n - diff; i++) {
        int j = i + diff;
        p[i][j] = s[i] == s[j];
        if (i + 1 <= j - 1) p[i][j] &= p[i + 1][j - 1];

        if (p[i][j]) si = i, ei = j;
      }
    }

    return s.substr(si, ei - si + 1);
  }
};
