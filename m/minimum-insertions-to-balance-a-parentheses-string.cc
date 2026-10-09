class Solution {
public:
  int minInsertions(string s) {
    int v = 0, ans = 0;
    for (char c : s) {
      if (c == '(') {
        if (v & 1) ++ans, --v;
        v += 2;
      }
      else {
        --v;
        if (v < 0) ++ans, v += 2;
      }
    }
    return ans + v;
  }
};
