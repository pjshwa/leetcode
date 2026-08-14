class Solution {
public:
  int maximumLengthSubstring(string s) {
    int N = s.size(), C[26]{}, l = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      int c = s[i] - 'a'; ++C[c];
      while (C[c] > 2) --C[s[l++] - 'a'];
      ans = max(ans, i - l + 1);
    }
    return ans;
  }
};
