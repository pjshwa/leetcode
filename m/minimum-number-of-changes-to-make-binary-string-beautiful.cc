class Solution {
public:
  int minChanges(string s) {
    int N = s.size(), ans = 0;
    for (int i = 0; i < N; i += 2) {
      ans += s[i] != s[i + 1];
    }
    return ans;
  }
};
