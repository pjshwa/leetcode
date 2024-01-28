class Solution {
public:
  int countKeyChanges(string s) {
    // lower case
    int N = s.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      s[i] = tolower(s[i]);
    }
    for (int i = 1; i < N; ++i) {
      if (s[i] != s[i - 1]) ++ans;
    }
    return ans;
  }
};
