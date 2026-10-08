class Solution {
public:
  string removeOuterParentheses(string s) {
    string ans; int cur = 0;
    for (char c : s) {
      if (c == '(' && cur++ > 0) ans += c;
      if (c == ')' && cur-- > 1) ans += c;
    }
    return ans;
  }
};
