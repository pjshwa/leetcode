class StringWP {
  vector<int> str, plen;
  int n;

  void manacher() {
    int r = -1, p = -1;
    for (int i = 0; i < n; ++i) {
      if (i <= r) plen[i] = min((2 * p - i >= 0) ? plen[2 * p - i] : 0, r - i);
      else plen[i] = 0;

      while (
        i - plen[i] - 1 >= 0 && i + plen[i] + 1 < n &&
        str[i - plen[i] - 1] == str[i + plen[i] + 1]
      ) plen[i] += 1;

      if (i + plen[i] > r) {
        r = i + plen[i];
        p = i;
      }
    }
  }

public:
  StringWP(string& s) {
    n = (s.size() << 1) + 1;
    str.resize(n);
    plen.resize(n);

    for (int i = 0; i < n; i++) {
      if (i % 2) str[i] = -1;
      else str[i] = s[i / 2];
    }

    manacher();
  }

  StringWP(vector<int>& s) {
    n = (s.size() << 1) + 1;
    str.resize(n);
    plen.resize(n);

    for (int i = 0; i < n; i++) {
      if (i % 2) str[i] = -1;
      else str[i] = s[i / 2];
    }

    manacher();
  }

  bool is_palindrome(int s, int e) {
    if (s > e) return true;
    s = (s - 1) << 1;
    e = (e - 1) << 1;
    return e - (s + e) / 2 <= plen[(s + e) / 2];
  }
};

class Solution {
public:
  string shortestPalindrome(string s) {
    auto wp = StringWP(s);
    int N = s.size();
    for (int i = N; i >= 1; --i) {
      if (!wp.is_palindrome(1, i)) continue;
      string res = s.substr(i);
      reverse(res.begin(), res.end());
      return res + s;
    }
    return "";
  }
};
