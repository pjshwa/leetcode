class Solution {
public:
  int minOperations(string s) {
    int N = s.size();

    int ans = N;
    for (int f : {0, 1}) {
      int cur = 0;
      for (char c : s) {
        int ci = c - '0';
        cur += (ci != f);
        f ^= 1;
      }
      ans = min(ans, cur);
    }
    return ans;
  }
};
