class Solution {
public:
  bool canBeValid(string s, string locked) {
    int N = s.size(), open = 0;
    if (N & 1) return false;

    int H = N / 2;
    for (int i = 0; i < N; ++i) {
      if (s[i] == '(' && locked[i] == '1') ++open;
    }
    if (open > H) return false;

    for (int i = 0; i < N; ++i) {
      if (locked[i] == '1') continue;
      if (open < H) {
        ++open;
        if (s[i] == ')') s[i] = '(';
      } else {
        if (s[i] == '(') s[i] = ')';
      }
    }

    int run = 0;
    for (int i = 0; i < N; ++i) {
      if (s[i] == '(') ++run;
      else --run;
      if (run < 0) return false;
    }
    return run == 0;
  }
};
