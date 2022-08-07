class Solution {
public:
  int longestIdealString(string s, int k) {
    int p[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      int x = s[i] - 'a', u = p[x];
      for (int j = x - k; j <= x + k; j++) {
        if (j < 0 || j >= 26) continue;
        u = max(u, p[j] + 1);
      }
      p[x] = u;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = max(ans, p[i]);
    }
    return ans;
  }
};
