class Solution {
public:
  int numKLenSubstrNoRepeats(string s, int k) {
    int C[26]{}, ans = 0, N = s.size(), over1_cnt = 0;
    if (N < k) return 0;
    for (int i = 0; i < k; ++i) {
      if (++C[s[i] - 'a'] == 2) ++over1_cnt;
    }
    if (over1_cnt == 0) ++ans;

    for (int i = k; i < N; ++i) {
      if (++C[s[i] - 'a'] == 2) ++over1_cnt;
      if (--C[s[i - k] - 'a'] == 1) --over1_cnt;
      if (over1_cnt == 0) ++ans;
    }
    return ans;
  }
};
