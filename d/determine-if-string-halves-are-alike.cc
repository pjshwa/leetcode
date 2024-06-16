class Solution {
  bool is_vowel(char c) {
    if (c >= 'A' && c <= 'Z') {
      c = c - 'A' + 'a';
    }
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  bool halvesAreAlike(string s) {
    int n = s.size(), vl = 0, vr = 0;
    for (int i = 0; i < n / 2; i++) {
      if (is_vowel(s[i])) vl++;
      if (is_vowel(s[n - i - 1])) vr++;
    }
    return vl == vr;
  }
};
