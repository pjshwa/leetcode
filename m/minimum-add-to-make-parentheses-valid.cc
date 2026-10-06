class Solution {
public:
  int minAddToMakeValid(string s) {
    int mmin = INT_MAX, cur = 0;
    for (char c : s) {
      c == '(' ? ++cur : --cur;
      mmin = min(mmin, cur);
    }
    return cur - 2 * min(0, mmin);
  }
};
