class Solution {
public:
  vector<vector<string>> partition(string s) {
    function<bool(int, int)> is_palindrome = [&](int i, int j) {
      while (i < j) {
        if (s[i++] != s[j--]) return false;
      }
      return true;
    };

    vector<vector<string>> ans;
    int n = s.size(), b = n - 1;

    for (int state = 0; state < (1 << b); state++) {
      int last = 0, f = 1;

      for (int i = 0; i < b; i++) {
        if (!(state & (1 << i))) continue;

        int l = last, r = i;
        if (!is_palindrome(l, r)) {
          f = 0;
          break;
        }
        last = i + 1;
      }
      f = f && is_palindrome(last, n - 1);
      if (!f) continue;

      vector<string> cur; last = 0;
      for (int i = 0; i < b; i++) {
        if (!(state & (1 << i))) continue;

        cur.push_back(s.substr(last, i - last + 1));
        last = i + 1;
      }
      cur.push_back(s.substr(last, n - last));
      ans.push_back(cur);
    }
    return ans;
  }
};
