class Solution {
  int c2v(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
  }

public:
  int romanToInt(string s) {
    int ans = 0, n = s.size(), i = 0;
    vector<tuple<char, char, char>> rules = {
      make_tuple('I', 'V', 'X'),
      make_tuple('X', 'L', 'C'),
      make_tuple('C', 'D', 'M')
    };
    while (i < n - 1) {
      bool f = false;
      for (auto [u, e1, e2] : rules) {
        if (s[i] == u && (s[i + 1] == e1 || s[i + 1] == e2)) {
          ans += c2v(s[i + 1]) - c2v(s[i]);
          f = true;
          break;
        }
      }

      if (f) i += 2;
      else {
        ans += c2v(s[i]);
        i += 1;
      }
    }

    ans += c2v(s[i]);
    return ans;
  }
};
