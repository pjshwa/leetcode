class Solution {
public:
  int maxDepth(string s) {
    int ans = 0, d = 0;
    for (char c : s) {
      if (c == '(') ++d;
      if (c == ')') --d;
      ans = max(ans, d);
    }
    return ans;
  }
};
