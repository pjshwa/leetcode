class Solution {
  int d[100'000][2][2], n;
  string s;

  bool is_palindrome(int i, bool fl, bool fr) {
    if (d[i][fl][fr] != -1) return d[i][fl][fr];

    int left = i + fl;
    int right = n - i - 1 - fr;

    bool res = s[left] == s[right] && (left >= right || is_palindrome(i + 1, fl, fr));
    if (!fl && !fr) {
      res = res || is_palindrome(i, false, true);
      res = res || is_palindrome(i, true, false);
    }
    return d[i][fl][fr] = res;
  }

public:
  bool validPalindrome(string s) {
    this->s = s;
    n = s.size();
    memset(d, -1, sizeof(d));
    return is_palindrome(0, false, false);
  }
};
