class Solution {
public:
  int maxScore(string s) {
    int cur = 0, N = s.size();
    for (char c : s) cur += c == '1';

    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
      char c = s[i];
      if (c == '1') --cur;
      else ++cur;
      ans = max(ans, cur);
    }

    return ans;
  }
};
