class Solution {
public:
  int maxUniqueSplit(string S) {
    int N = S.size(), ans = 0;
    for (int s = 0; s < (1 << (N - 1)); ++s) {
      unordered_set<string> seen;
      int i = 0;
      for (int j = 0; j < N; ++j) {
        if (s & (1 << j)) {
          seen.insert(S.substr(i, j - i + 1));
          i = j + 1;
        }
      }
      seen.insert(S.substr(i));

      int cnt = __builtin_popcount(s) + 1;
      if (seen.size() == cnt) ans = max(ans, cnt);
    }
    return ans;
  }
};
