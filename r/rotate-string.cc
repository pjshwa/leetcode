class Solution {
public:
  bool rotateString(string s, string goal) {
    int N = s.size();
    if (goal.size() != N) return false;

    for (int off = 0; off < N; ++off) {
      int ok = 1;
      for (int i = 0; i < N; ++i) {
        ok &= s[i] == goal[(i + off) % N];
      }
      if (ok) return true;
    }
    return false;
  }
};
