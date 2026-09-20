class Solution {
public:
  int reverseDegree(string s) {
    int i = 0, ans = 0;
    for (char c : s) ans += ++i * (26 + 'a' - c);
    return ans;
  }
};
