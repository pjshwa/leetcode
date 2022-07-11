class Solution {
  bool is_palindrome(string& s, int si, int ei) {
    int n = ei - si;
    for (int i = 0; i < n / 2; i++) {
      if (s[si + i] != s[ei - i - 1]) return false;
    }
    return true;
  }
public:
  vector<vector<string>> partition(string s) {
    int n = s.size();

    vector<vector<string>> ans;
    for (int state = 0; state < (1 << (n - 1)); state++) {
      bool all_palindrome = true;
      int li = 0;
      for (int j = 0; j < n - 1; j++) {
        if (state & (1 << j)) {
          all_palindrome &= is_palindrome(s, li, j + 1);
          li = j + 1;
        }
      }
      all_palindrome &= is_palindrome(s, li, n);

      if (!all_palindrome) continue;

      vector<string> partitions;
      li = 0;
      for (int j = 0; j < n - 1; j++) {
        if (state & (1 << j)) {
          partitions.push_back(s.substr(li, j - li + 1));
          li = j + 1;
        }
      }
      partitions.push_back(s.substr(li));
      ans.push_back(partitions);
    }

    return ans;
  }
};
