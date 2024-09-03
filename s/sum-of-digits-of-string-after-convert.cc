class Solution {
public:
  int getLucky(string s, int k) {
    int ans = 0;
    for (char c : s) {
      int ci = c - 'a' + 1;
      ans += ci / 10 + ci % 10;
    }
    while (--k) {
      int next = 0;
      while (ans) next += ans % 10, ans /= 10;
      ans = next;
    }
    return ans;
  }
};
