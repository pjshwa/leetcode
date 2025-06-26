class Solution {
public:
  int longestSubsequence(string s, int k) {
    int N = s.size(), val = 0, ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < N; ++i) {
      if (s[i] - '0') {
        if (i < 30 && (val | (1 << i)) <= k) {
          val |= (1 << i);
          ++ans;
        }
      }
      else ++ans;
    }
    return ans;
  }
};
