class Solution {
  int d[1000][1000];
  string s;

  bool is_palindrome(int l, int r) {
    if (d[l][r] != -1) return d[l][r];

    bool res;
    if (l == r) res = true;
    else if (s[l] == s[r]) {
      if (l + 1 == r) res = true;
      else res = is_palindrome(l + 1, r - 1);
    }
    else res = false;

    return d[l][r] = res;
  }

public:
  int countSubstrings(string s) {
    this->s = s;
    int n = s.size();
    memset(d, -1, sizeof(d));

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
      ans += is_palindrome(i, j);
    }

    return ans;
  }
};
