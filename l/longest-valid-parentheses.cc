class Solution {
public:
  int longestValidParentheses(string s) {
    map<int, int> T; int ans = 0, o = 0, N = s.size();
    for (int i = 0; i < N; ++i) {
      char c = s[i];
      if (c == '(') {
        if (!T.count(o)) T[o] = i - 1;
        ++o;
      }
      else {
        T.erase(o--);
        if (T.count(o)) ans = max(ans, i - T[o]);
      }
    }
    return ans;
  }
};
