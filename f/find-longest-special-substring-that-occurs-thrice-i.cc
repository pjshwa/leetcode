class Solution {
public:
  int maximumLength(string s) {
    int ans = -1, N = s.size();
    int l = 1, r = N;
    while (l < r) {
      int C[26]{}, str = 0, m = (l + r) / 2;
      for (int i = 0; i < N; ++i) {
        if (i == 0 || s[i] == s[i - 1]) ++str;
        else str = 1;
        if (str >= m) ++C[s[i] - 'a'];
      }
      if (*max_element(C, C + 26) >= 3) l = m + 1;
      else r = m;
    }
    if (l > 1) ans = max(ans, l - 1);
    return ans;
  }
};
