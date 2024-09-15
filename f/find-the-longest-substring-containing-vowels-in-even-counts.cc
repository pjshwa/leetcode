class Solution {
public:
  int findTheLongestSubstring(string s) {
    int D[32], O[32]{}, f = 0, ans = 0, N = s.size();
    memset(D, -1, sizeof(D)); O[0] = 1;
    for (int i = 0; i < N; ++i) {
      char c = s[i];
      if (c == 'a') f ^= 1;
      if (c == 'e') f ^= 2;
      if (c == 'i') f ^= 4;
      if (c == 'o') f ^= 8;
      if (c == 'u') f ^= 16;

      if (O[f]) ans = max(ans, i - D[f]);
      else O[f] = 1, D[f] = i;
    }
    return ans;
  }
};
